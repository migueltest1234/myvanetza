#include <gtest/gtest.h>
#include <vanetza/common/byte_sequence.hpp>
#include <vanetza/security/v2/recipient_info.hpp>
#include <vanetza/security/tests/check_recipient_info.hpp>
#include <vanetza/security/tests/serialization.hpp>

using namespace vanetza;
using namespace vanetza::security;
using namespace vanetza::security::v2;

TEST(RecipientInfo, Serialize)
{
    EciesEncryptedKey ecies;
    ecies.v = Compressed_Lsb_Y_0 { random_byte_sequence(field_size(PublicKeyAlgorithm::ECIES_NISTP256), 1337) };
    auto cbuf = random_byte_sequence(field_size(SymmetricAlgorithm::AES128_CCM), 7331);
    ecies.c = { cbuf.begin(), cbuf.end() };
    auto tbuf = random_byte_sequence(ecies.t.size(), 1234);
    std::copy_n(tbuf.begin(), ecies.t.size(), ecies.t.data());
    RecipientInfo info;
    info.enc_key = ecies;
    auto certbuf = random_byte_sequence(info.cert_id.size(), 4321);
    std::copy_n(certbuf.begin(), info.cert_id.size(), info.cert_id.data());

    check(info, serialize_roundtrip(info, SymmetricAlgorithm::AES128_CCM));
}
