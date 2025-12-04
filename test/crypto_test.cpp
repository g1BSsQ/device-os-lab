#include "crypto/crypto.h"
#include <gtest/gtest.h>

// Example test case for crypto library
TEST(CryptoLibraryTest, EncryptFunction) {
    std::string plaintext = "Hello, World!";
    std::string key = "secretkey";
    std::string ciphertext = encrypt(plaintext, key);

    ASSERT_FALSE(ciphertext.empty());
    ASSERT_NE(plaintext, ciphertext);
}

TEST(CryptoLibraryTest, DecryptFunction) {
    std::string plaintext = "Hello, World!";
    std::string key = "secretkey";
    std::string ciphertext = encrypt(plaintext, key);
    std::string decrypted = decrypt(ciphertext, key);

    ASSERT_EQ(plaintext, decrypted);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}