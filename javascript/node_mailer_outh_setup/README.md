# Setup gmail OAuth2 with nodemailer.
- go to google cloud `https://console.cloud.google.com/`
- search for `api and service`
- crete new project
- then go to `credentials`
- create new `Outh client ID` under `create new credentiala`. (you may need to setup OAuth consent screen to be able to create new credentials).
- on creating new crendentials choose `web application` as type.
- set Authorize redirect as : `https://developers.google.com/oauthplayground`.
- then copy the given `client_id` and `client_secret`.

# on outhplayground website.
- on setting (gear wheel) icon, click it and enable `use your own Outh credentials`
- fill in the `client_id` and `client_secret` you copied earlier and hit `close`.
- on left side where it says `select and Authorize API`. paste this : `https://mail.google.com`.
- then click authorize api.
- a new tab will redirect to your google login page.
- login to your account (amil sender). and approve the API.
- click : `Exchange authorization code for tokens` and then copy the refresh token.
- we are now ready to write our code.

# In Node.js.
- install nodemailer.
- install `googleapis` using : `npm install googleapis`.  
- crate new mailing service. (I usually create it under path: `lib/mailer.js`
- inside that file import googleapis and nodemailer.
```js
const mailer = require('nodemailer');
const {google} = require('googleapis');

```
- create new oAuth2 client using by passing our `client_id`,`client_secret` and our Authorize redirect address, which is the google oauthplayground :  `https://developers.google.com/oauthplayground`. 
```js
const oAuth2Client = new google.Auth.OAuth2(
	`OUR_CLIENT_ID`,
	`OUR_CLIENT_SECRET',
	`OUR_AUTH_REDIRECT`,
);
```
- then set our refresh token to out OAuth2Client by passing the refresh token we copied earlier.
```js
oAuth2Client.setCredentials(OUR_RF_TOKEN);
```
- then we can get the accessToken to our emailservice from the OAuth2Client.
```js
const accessToken = oAuth2Client.getAccessToken();
```
- using that accessToken, we can send mail using nodemailer by setting the `Auth` `type`  options to `OAuth2`.
- example nodemailer transporter.
```js
const transporter = nodemailer.createTransport({
	service: 'gmail',
	auth : {
		type: 'OAuth2',
		user: 'sendergmailaddress@gmail.com',
		clientId: 'OUR_CLIENT_ID_COPIED_EARLIER',
		clientSecret: 'OUR_CLIENT_SECRET',
		accessToken,
	},
});
```
