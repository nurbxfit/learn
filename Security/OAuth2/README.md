# OAuth

- oAuth is used to share information from one domain with another domain.
- it enable one domain let say `mysite.com` to request limited access to user's account on another domain let say `google.com`.
- `mysite.com` is considered a third-party, to handler user information from `google.com`.
- user don't provide any login credentials to `mysite.com`
- `mysite.com` only have the authorized user information given by `google.com`.
- OAuth consist of 3 or 4 main entities:
  - `Client application` : the third party that want the user information,eg: `mysite.com`.
  - `Resource owner` : the user, that are going to give away their info
  - `OAuth service provider`: server that provide authentication and authortization token to access resources server.
  - `Resources Server` : API server storing the resources, usually own by service provider.

# Grant types.

- Also known as `OAuth Flows`.
- [OAuth grant types](https://oauth.net/2/grant-types/) are ways application, can get an access token from the provider.
- it's a flow of process for `Client Application` to get `Access Token` from `OAuth Service Provider`.
- basically, the provider can defined and configure their specific grant types, for client to use.
- 5 commons grant types are
  - Authorization code Grant Type
  - Implicit Grant Type
  - Resource Owner Credential Grant Type
  - Client Credentials Grant Type
  - Refresh Token Grant Type.

# OAuth Scope

- For each grant types, there are scopes that need to be defines.
- `scopes` describe which data it wants to access, and what operation it wants to perform.
- client specify the scopes in its authorization request send to provider.
- the scope is send in request URI in plain strings parameters.
- example client wanting to access contacts information look like this

```
scope=contacts
scope=contacts.read
scope=contacts.readonly
```

- it can be either one of these, it's all depends on how service provider configure their API.

# How does OAuth work (basic flow)?

- firstly, the user (`Resource Owner`) go to mysite.com (`Client Application`) and click the `sign up with google` button.
- the `Client Application` make a request to google (`OAuth Service Provider`), saying wanting to access user's data (scopes) using some specific grant types let say `Authorization Grant type`.
- the `Resource Owner` then prompted with a Login page, to authenticate with `OAuth Service Provider`.
- afther authenticated, `OAuth Service Provider` will ask `Resource Owner` need to give permission/consent to `Client Application` to access requested data.
- by clicking `Allow`, `OAuth Service Provider` then send unique `access token` to `Client Application` for it to use to make future request to `Resources Server` API to get user's information.

## note: process of getting AccessToken vary depends of Grant types used.

# Grant Types Example.

- almost all grant types follow the basic OAuth flow, with just slight different based on the Grant type they uses.

## Authorization Code Grant type.

- it follows the basic flow, of client making a request, prompt login, and click allow to give consent.
- the different is that, the flow after the resource owner give the permission.
- how the client application receive response and make a request for access token, depends on the Grant type (flows).
- here are diagram for `Authorization Code` Grant Type taken from portswigger.
  ![auth flow](https://portswigger.net/web-security/images/oauth-authorization-code-flow.jpg)

> When OAuth is used for authentication, however, the standardized OpenID Connect scopes are often used instead. For example, the scope openid profile will grant the client application read access to a predefined set of basic information about the user, such as their email address, username, and so on. We'll talk more about OpenID Connect later.
> (from: portswigger)

## Client Application Authorization Request to Service Provider.

- in this example, we follow our previous example, where our Client Application is `mysite.com` and our provider is `google.com`
- note that this is an example, and might not reflect the real OAuth method used by google.com
- client application request look like this, when it send to OAuth provider.

```http
GET /Auth?client_id=12345&redirect_uri=htts://mysite.com/callback&response_type=code&scope=openid%20profile&state=736f6d656f6e65 HTTP/1.1
Host: oauth.google.com
```

- the request containst.
- unique `client_id`, we got from registring OAuth service with service provider.
- `redirect_uri` pointing to client app API that will handle the response sent back by service provider, (webhook).
- `response_type`; this is the Grant type we want to use, in this case `code` is the value for Authorization `code` grant type.
- `scope`; the scope we discuss earlier, in this case, we want to access `profile` based on OpenID spec. (our scope=openid profile)
  - openid scope includes:
    - profile (we are using in our example)
    - email
    - address
    - phone
  - each of these scope provide read access to user information defined by openid spec.
- `state` is a unique value can be a token, it purpose is just like CSRF token in form.
  - we gave this unique value to OAuth provider so that
    service provider can then sent response with this unique value included to our redirect_uri/callback, for our Client Application to verify that, the response we received is from the request we issued earlier.

## Service Provider respond to Client Application webhook.

- here is when service provider, gives `Authorization token grant` to our Client Application.
- Service provider will make a request to our API callback, specified by the `redirect_uri` we provided in our initial request.
- service provider will provide authorization `code` to our API to be used by our application to make request to get a token.
- and then use that token to get user's infrmation from `resource server`.

```http
GET /callback?code=a1b2c3d4e5f6g7h8&state=736f6d656f6e65 HTTP/1.1
Host: myapp.com
```

- the `code` is the authorization code.
- the `state` is unique value we sent earlier in our request.
- then using the `code` given by service provider, we can make a request for an accessToken.

## Requesting for Access Token from Service Provider.

- after we received our authroization code, we can use it to request for an access token.
- we make a server-to-server `POST` request to service provider.

```http
POST /token HTTP/1.1
Host: oauth.google.com
...
client_id=12345&client_secret=736f6d6572616e646f6d7468696e6773&redirect_uri=https://myapp.com/callback&grant_type=authorization_code&code=a1b2c3d4e5f6g7h
```

- here we sent together.
  - `client_id`
  - `client_secret` ; we get from registering OAuth service with service provider.
  - `redirect_uri` ; our callback
  - `grant_type` ; grant type we are using is authorization_code.
  - authorization `code` ; we receive from our previous request

## Unfinish need to sleep