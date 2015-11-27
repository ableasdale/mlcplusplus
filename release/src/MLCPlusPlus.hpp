
#ifndef __MLCPlusPlus__
#define __MLCPlusPlus__

#include "cpprest/http_client.h"

#include <string>

class Connection {

public:
    Connection();
    ~Connection();

    void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, const bool usessl);
    void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password);
    // TODO anonymous connection support
    // TODO Kerberos connection support
    // TODO test BASIC and DIGEST and BASIC+DIGEST authentication methods

    Response get(const std::string& uri);
    Response save(const std::string& uri,const web::json::value& payload);
    // TODO save JSON with directory, no uri
    // TODO optional parameters (collection, security, etc.)
    // TODO save XML with and without URI

    // Multi part MIME saveAll function V7+
    Response saveAll(const std::string& uris[], const web::json::value& documents[]);
    // TODO XML save all
    // TODO multiple responses when paging in N number of doc transactions

    Response search(const web::json::value& searchQuery,const std::string& options);
    // TODO search with options document (combined query)
    Response search(const web::json::value& searchQuery,const web::json::value& options);
    Response Connection::search(const web::json::value& searchQuery,const std::string& qtext);
    Response Connection::search(const web::json::value& searchQuery,const std::string& qtext,const web::json::value& options);
    // TODO search with XML instead of JSON

private:
    std::string& _serverUrl;
    AuthenticatingProxy& _proxy;

    // prevent compiler automatically defining the copy constructor and assignment operator:-
    Connection(const Connection&);
    Connection& operator= (const Connection&);
};

#endif /* defined(__MLCPlusPlus__) */
