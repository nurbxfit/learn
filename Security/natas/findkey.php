<?php
$defaultdata= array( "showpassword"=>"no", "bgcolor"=>"#ffffff");
$cookie = "ClVLIh4ASCsCBE8lAxMacFMZV2hdVVotEhhUJQNVAmhSEV4sFxFeaAw%3D";

function xor_encrypt($in) {
    // $key = '<censored>';
    global $cookie;
    $key = base64_decode($cookie);
    $text = $in;
    $outText = '';

    // Iterate through each character
    for($i=0;$i<strlen($text);$i++) {
    $outText .= $text[$i] ^ $key[$i % strlen($key)];
    }

    return $outText;
}

$key = xor_encrypt(json_encode($defaultdata));
echo "key: $key \n";