function vigenereCipherEncryption() {

  function isLetter(str) {
    return str.length === 1 && str.match(/[a-zA-Z]/i);
  }

  function isUpperCase(character) {
    if (character === character.toUpperCase()) {
      return true;
    }
    if (character === character.toLowerCase()) {
      return false;
    }
  }

  function encrypt(message, key) {
    let result = "";

    for (let i = 0, j = 0; i < message.length; i++) {
      const c = message.charAt(i);
      if (isLetter(c)) {
        if (isUpperCase(c)) {
          result += String.fromCharCode(
            ((c.charCodeAt(0) + key.toUpperCase().charCodeAt(j) - 2 * 65) %
              26) +
              65
          ); // A: 65
        } else {
          result += String.fromCharCode(
            ((c.charCodeAt(0) + key.toLowerCase().charCodeAt(j) - 2 * 97) %
              26) +
              97
          ); // a: 97
        }
      } else {
        result += c;
      }
      j = ++j % key.length;
    }
    return result;
  }

  let plainText = document.getElementById("userText").value;
  // plainText = plainText.toUpperCase();
  console.log(plainText);

  let keyword = document.getElementById("keyword").value;
  if (keyword.length > 0) {
    keyword = keyword.replace(/[^A-Z0-9]/gi, "");
    keyword.toUpperCase();
  }
  console.log(keyword);

  let cipherText = encrypt(plainText, keyword);
  document.getElementById("output").value = cipherText;

  console.log(cipherText);
  let container = document.createElement("textarea");
  container.value = cipherText;
}

function vigenereCipherDecryption() {
  function isLetter(str) {
    return str.length === 1 && str.match(/[a-zA-Z]/i);
  }

  function isUpperCase(character) {
    if (character === character.toUpperCase()) {
      return true;
    }
    if (character === character.toLowerCase()) {
      return false;
    }
  }


  function decrypt(message, key) {
    let result = "";

    for (let i = 0, j = 0; i < message.length; i++) {
      const c = message.charAt(i);
      if (isLetter(c)) {
        if (isUpperCase(c)) {
          result += String.fromCharCode(
            90 -
              ((25 - (c.charCodeAt(0) - key.toUpperCase().charCodeAt(j))) % 26)
          );
        } else {
          result += String.fromCharCode(
            122 -
              ((25 - (c.charCodeAt(0) - key.toLowerCase().charCodeAt(j))) % 26)
          );
        }
      } else {
        result += c;
      }
      j = ++j % key.length;
    }
    return result;
  }

  let cipherText = document.getElementById("userText").value;
  // plainText = plainText.toUpperCase();
  console.log(cipherText);

  let keyword = document.getElementById("keyword").value;
  if (keyword.length > 0) {
    keyword = keyword.replace(/[^A-Z0-9]/gi, "");
    keyword.toUpperCase();
  }
  console.log(keyword);

  let originalText = decrypt(cipherText, keyword);
  document.getElementById("output").value = originalText;

  console.log(originalText);
  let container = document.createElement("textarea");
  container.value = originalText;
}
