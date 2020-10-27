# Simple Example of importing multiple .js file from a folder.
- files inside the `routes` folder get imported by the `index.js` file.
- `index.js` then export all the imported files.
- we can latter import those many files inside `routes` with only a single line import  : `require('./index')`.
- app.js can use the files inside `routes` without having to write `require` one by one.

# run the example
  - `node app.js`
