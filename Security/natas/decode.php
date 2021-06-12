<?php

$cookie = "R0EWBhwYAgQXTUsMFwpRVVALCxwQQQcJEAAeChYcBkFGCBUJFAMCHEE=";
function xor_encrypt($in) {
    $key = '<censored>';
    $text = $in;
    $outText = '';

    // Iterate through each character
    for($i=0;$i<strlen($text);$i++) {
    $outText .= $text[$i] ^ $key[$i % strlen($key)];
    }

    return $outText;
}

$decrypt = xor_encrypt(base64_decode($cookie));
echo "$decrypt \n";