const form = document.getElementById("form");
const email = document.getElementById("email");
const password = document.getElementById("password");

//show error message
function showError(input, message) {
  const formControl = input.parentElement;
  formControl.className = "form-control error";
  const small = formControl.querySelector("small");
  small.innerText = message;
}

//show green success
function showSuccess(input, message) {
  const formControl = input.parentElement;
  formControl.className = "form-control success";
}

//check all field required
function checkRequired(fields) {
  fields.forEach(function (field) {
    if (field.value.trim() === "") {
      showError(field, `${field.id} is required`);
    }
  });
}
//check email
function checkEmail(input) {
  const emailRegex =
    /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  if (emailRegex.test(input.value.trim())) {
    showSuccess(input);
  } else {
    showError(input, "Invalid Email");
  }
}
//check password

//check valid Length
function checkLength(input, min, max) {
  if (input.value.trim().length < min) {
    showError(input, `Must be more than ${min} characters`);
  } else if (input.value.trim().length > max) {
    showError(input, `Must be less than ${max} characters`);
  } else {
    showSuccess(input);
  }
}
//add event listener
form.addEventListener("submit", function (event) {
  event.preventDefault(); //prevent it from submit.

  //run our checking function
  checkRequired([email, password]);
  checkLength(email, 3, 15);
  checkLength(password, 6, 25);
  checkEmail(email);
});
