# Generate static frontend file
- let say we want to deploy our REST website on a linux server.
- we have the fronend angular, and backend express/node.js REST api.
- the first generate our frontend file using : `ng build` 
- we will get bunch of `.js` file and `index.html` file inside of our `dist/project-name` folder
- copy our project folder inside the `dist` folder into our `/var/www` folder.

# configure httpd/apache to host that file.
- we can directly edit httpd config file in `/etc/httpd/conf/httpd.conf`
- or we can create new config file in `/etc/httpd/conf.d/` and include that file from `httpd.conf`
- (first option) inside `/etc/httpd/conf/httpd.conf`.
  - for basic config, we set DocumentRoot to `/var/www/OurProject-folder`.
  - then:
  ```
  <Directory "/var/www/OurProject-folder">
    AllowOverride None
    FallbackResource ./index.html
    Options Indexes FollowSymLinks
    Require all granted
  </Directory>
  ```
  - these few lines, tells httpd to use our project folder contain `index.html` as root of our server.
  - then restart httpd or apache using `systemctl restart httpd.service`.

# enable reverse Proxy in httpd.
- in rest website, our frontend will communicate with our backend api.
- let say our node.js or flask server running on the same server on port 4545
- instead of playing with iptables to open external excess to the api on port 4545, we use httpd/apache as proxy on port 80.
- httpd will redirect request for api from our fronend to the backend api.
- NOTE: our backend api running on `http://0.0.0.0:4545/`

- we need these modules to enable httpd reverse proxy.
  - `proxy_module`
  - `lbmethod_byrequests_module`
  - `proxy_balancer_module`
  - `proxy_http_module`
- we can check if our modules are loaded by opening `/etc/httpd/conf.modules.d/00-proxy.conf`
- if the name of our modules is commented, uncomment it to use it.
- then inside of `/etc/httpd/conf.d/`.
  - create new config file name: `default-site.conf`
  - inside the newly create file, paste this config.
   -
   ```
   <VirtualHost *:80>
    ProxyPreserveHost On

    ProxyPass /api/ http://0.0.0.0:4545/
    ProxyPassReverse /api/ http://0.0.0.0:4545/
  </VirtualHost>
   ```
   - if our website is listening on different IP or different server in internal network, replace the `http://0.0.0.0:4545/` with your website ip.
   - the `/api/` tells the proxypass to redirect request with `/api/` to our api server.
   - so let say our frontend running on `testangular.com`
   - by sending request to `testangular.com/api` all the request will be redirect to our internal backend api. 

# side note:
   - if our server is RHEL base server running SELinux.
   - we need to setsebool to `setsebool -P httpd_can_network_connect on`
   - otherwise we will get 503 error message from the httpd, when visiting `/api`
