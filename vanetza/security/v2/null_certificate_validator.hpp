#ifndef NULL_CERTIFICATE_VALIDATOR_HPP_3L9RJY2A
#define NULL_CERTIFICATE_VALIDATOR_HPP_3L9RJY2A

#include <vanetza/security/v2/certificate_validator.hpp>

namespace vanetza
{
namespace security
{
namespace v2
{

class NullCertificateValidator : public CertificateValidator
{
public:
    NullCertificateValidator();

    CertificateValidity check_certificate(const Certificate&) override;

    /**
     * Set predefined result of check_certificate() calls
     * \param result predefined result
     */
    void certificate_check_result(const CertificateValidity& result);

private:
    CertificateValidity m_check_result;
};

} // namespace v2
} // namespace security
} // namespace vanetza

#endif /* NULL_CERTIFICATE_VALIDATOR_HPP_3L9RJY2A */
