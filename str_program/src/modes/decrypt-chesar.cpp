#include <string>

std::string decode(std::string string, int shift) {
    std::string final_string = "";
    size_t string_size = string.length();
    int alph_size = 'z' - 'a' + 1;

    for (int idx = 0; idx < string_size; idx++) {
        char string_char = string[idx];
        if(!isalpha(string_char)) continue;

        int effective_shift = shift % alph_size;

        if (effective_shift < 0) {
            effective_shift += alph_size;
        }

        if ((string_char >= 'A' && string_char <= 'Z') || (string_char >= 'a' && string_char <= 'z')) {
            int effective_char = string_char < 'a' ? 'A' : 'a';
            string_char = ((string_char - effective_char - effective_shift + alph_size) % alph_size) + effective_char;
        }

        final_string += string_char;
    }

    return final_string;
}