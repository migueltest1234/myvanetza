#include <gtest/gtest.h>
#include <vanetza/common/byte_sequence.hpp>
#include <vanetza/security/signature.hpp>
#include <vanetza/security/tests/check_ecc_point.hpp>
#include <vanetza/security/tests/check_signature.hpp>
#include <vanetza/security/tests/check_visitor.hpp>
#include <boost/variant/apply_visitor.hpp>

namespace vanetza
{
namespace security
{

void check(const EcdsaSignature& expected, const EcdsaSignature& actual)
{
    check(expected.R, actual.R);
    EXPECT_EQ(expected.s, actual.s);
}

void check(const EcdsaSignatureFuture& expected, const EcdsaSignatureFuture& actual)
{
    check(expected.get(), actual.get());
}

EcdsaSignature create_random_ecdsa_signature(int seed)
{
    const std::size_t field = v2::field_size(v2::PublicKeyAlgorithm::ECDSA_NISTP256_With_SHA256);
    EcdsaSignature signature;
    signature.s = random_byte_sequence(field, seed);
    signature.R = X_Coordinate_Only { random_byte_sequence(field, ~seed) };
    return signature;
}

namespace v2
{

void check(const Signature& expected, const Signature& actual)
{
    ASSERT_EQ(get_type(expected), get_type(actual));
    // TODO boost::apply_visitor(check_visitor<Signature>(), expected, actual);
}

} // namespace v2
} // namespace security
} // namespace vanetza
