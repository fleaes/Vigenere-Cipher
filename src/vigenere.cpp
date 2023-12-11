#include <iostream>
#include <string>

std::string message;
std::string mappedKey;

void displayASCII();

void getMessageAndKey() {
    std::cout << "Enter your message: ";
    getline(std::cin, message);

    std::cout << "Enter your key: ";
    getline(std::cin, mappedKey);
}

std::string vigenereEncrypt(const std::string& input, const std::string& key) {
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (isalpha(c)) {
            char keyChar = key[i % key.length()];
            char encryptedChar = ((c + keyChar - 2 * 'a') % 26) + 'a';
            result += encryptedChar;
        }
        else {
            result += c;
        }
    }
    return result;
}

std::string vigenereDecrypt(const std::string& input, const std::string& key) {
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (isalpha(c)) {
            char keyChar = key[i % key.length()];
            char decryptedChar = ((c - keyChar + 26) % 26) + 'a';
            result += decryptedChar;
        }
        else {
            result += c;
        }
    }
    return result;
}

int main() {

    int choice;

    displayASCII();
    std::cout << "Please choose an option to encrypt or decrypt a message using a Vigenere Cipher:" << std::endl;
    std::cout << "Reminder, your message and key can only be alphabetic!" << std::endl << std::endl;
    std::cout << "1. Encryption" << std::endl;
    std::cout << "2. Decryption" << std::endl;
    std::cin >> choice;
    std::cin.ignore();

    getMessageAndKey();

    switch (choice) {
    case 1:
        std::cout << "Encryption Result: " << vigenereEncrypt(message, mappedKey) << std::endl;
        break;
    case 2:
        std::cout << "Decryption Result: " << vigenereDecrypt(message, mappedKey) << std::endl;
        break;
    default:
        std::cout << "Invalid Choice! Please choose option 1 or 2." << std::endl;
    }

    return 0;
}

void displayASCII() {
    const char* thumbsupChiyo = R"(                                                                                                                                                                                              
                                                                       ...::.........:::..::.                                     
                                                                ......:                      ::.....                              
                                                              .:                                    :...                          
                                                            .:                                           :..                       
                                                         .:                                                 :                       
                                                     . :                    .      ..                       ::                     
                                                     :                      .      . .                          .                 
                                                                           ..     .                              :                 
                                                   .  :                   ...    .      .   ..                     :               
                                                    .                   : .             .   ..                     :              
                                               . ..              .   ..: .  ..             . .                     .             
                   EASY ENCRYPTION!!!         :   .            : .  :       .           ...         :.              .            
                                              .   .    .       : .  :      .                    .    .                :           
                                                ..           :.  :       :..               .-    .   : .              :           
                                                    .       ..            .                       .  . .  ..          .           
                                               .  .    .    :   .:...:....                          ..  .  :          :.          
                             ...               ..   .  ....    :          ..               ....:....      . ..         .           
                          ..     .             .:   .   .                                .:        :.       ..         .  .        
                          :       :              :  ...  :                                                  .  .:     :   :        
                        .         .              .    .  .                                                   . .  .  .     :       
                        :         -              .     : :                       :                            ::  :  .      :      
                        .         :               .      .                                                            .     .     
                        :         :                :     :               ............ ... :                  :.       :      .    
                        :           ..              .. . .             . .                  .               ..       .        :    
                        :             .                  :             .                     :                     .:          :   
                      ......           :                                :                    :             .     .:            :  
                  ...        ..        .                  .             .                    .            .    ..              .  
              ::.                      :                  :.            .                   .            .:...:                :  
          ..:                      .: ..                 :    ..         .                 .           .                       .  
         .                          :      .           .        .          : .............:          .     .                   :  
        ..     ..: ........ .:.         -. ..         .           .  ..      .                   ..  .   .                    .   
     ..                           .     :       .....                  .  ..   ......      ....            :                  :   
    :                                    :          .  ..     ....           .  .::. .:..        . .        :                 :    
    :                                    .            .   ...       ..              .      ...  .  :         .               :     
    :                              .: .  :               ..            ..          :.              :          .             :      
    :            .. ............ . .     .                 .. .           .       .    . .     .. ..            .         ..      
     :                               :   :                     .             ..   :.              :               .      .        
     .                              :..  .                                      ....  .          .::  .            .    .         
      .                            .  :  .                                        ..    ... ... ..      ..            .           
       :                           .  .   .                                        .                      .                       
       :            ... :. .:. ...    .   .                                        ..                       .                     
         .                       :     .  :                                        ..                        .                    
           ..                    .     .  .                                         :                                             
              :                 :   ..    :                                          :               ::         :                  
               .  .        .::.  .   .   .                                          .:   .                      .                 
                :. ...... ..        :                                    ..             ...                     :                 
                                                                      ..             :.                          .                
                                  .  .                            ...                ..                          .                
                                .                           ..:..                                    .:    .                      
                     . ..       . ..                  ....                           ..              ..     .                     
                        .        ..         .. .::..:  :                                                    ..     ..             
                            ::..:. ...... . ..        :                               ..                                          
                                                      :                                 .  -.                         .           
                                                     :                                 ..                                         
                                                     :                                 :.                       .                 
          
)";
    std::cout << thumbsupChiyo;
}