//
//  AuthenticatingProxy.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <string>
#include <iostream>
#include "NoCredentialsException.hpp"
#include "AuthenticatingProxy.hpp"
#include "Credentials.hpp"

#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include "ResponseCodes.hpp"

const std::string DEFAULT_KEY = "__DEFAULT";

using namespace web;
using namespace utility;

void AuthenticatingProxy::AddCredentials(const Credentials &c) {
    _credentials = c;
}

Credentials AuthenticatingProxy::GetCredentials() const {
    return _credentials;
}

Response AuthenticatingProxy::Get(const std::string& host,
                                  const std::string& path,
                                  const header_t& headers,
                                  const params_t& body)
{
  Response response;
  header_t request_headers = headers;
  
  std::cerr << "checking if we need to authenticate" << std::endl;
  if (_credentials.Authenticating()) {
    _credentials.SetCredentials(path, request_headers);
  }
  
  std::cerr << "Creating client for host: " << host << std::endl;
  http::client::http_client raw_client(U(host));
  std::cerr << "Invoking request" << std::endl;
  std::cerr << "Attempting request for " << path << std::endl;

  try { 
    raw_client.request(http::methods::GET, U(path)).then([&response](http::http_response raw_response) {
      std::cerr << "Handling response" << std::endl;
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      std::cerr << "Response code: " << int((ResponseCodes)raw_response.status_code()) << std::endl;
      response.SetResponseHeaders(raw_response.headers());
    }).wait();
  } catch(std::exception e) {
    std::cerr << e.what() << std::endl;
  }

  std::cerr << "The response code " << int(response.GetResponseCode()) << std::endl;
  std::cerr << "Checking Response code to see if we need to authenticate" << std::endl;
  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    header_t response_headers = response.GetResponseHeaders();
    std::cerr << "Authenticating" << std::endl;
    _credentials.Authenticate("GET", path, response_headers, request_headers);
    std::cerr << "Restarting the request" << std::endl;
    return Get(host, path, request_headers, body);
  }
    
  return response;
}

Response AuthenticatingProxy::Get(const std::string& host, const std::string& path, const header_t& headers) {
    params_t blank_parameters;
    return Get(host, path, headers, blank_parameters);
}

Response AuthenticatingProxy::Get(const std::string& host, const std::string& path) {
    header_t blank_headers;
    return Get(host, path, blank_headers);
}

void AuthenticatingProxy::Get_Async(const std::string& host,
                                    const std::string& path,
                                    const header_t& headers,
                                    const params_t& body,
                                    const std::function<void(const Response&)> handler)
{
    
}

void AuthenticatingProxy::Get_Async(const std::string& host,
                                    const std::string& path,
                                    const header_t& headers,
                                    const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Get_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Get_Async(const std::string& host,
                                    const std::string& path,
                                    const std::function<void(const Response&)> handler)
{
    header_t blank_heders;
    Get_Async(host, path, blank_heders, handler);
}

Response AuthenticatingProxy::Post(const std::string& host,
                                   const std::string& path,
                                   const header_t& headers,
                                   const params_t& body)
{
    Response response;
    
    return response;
}

Response AuthenticatingProxy::Post(const std::string& host, const std::string& path, const header_t& headers)
{
    params_t blank_params;
    return Post(host, path, headers, blank_params);
}

Response AuthenticatingProxy::Post(const std::string& host, const std::string& path)
{
    header_t blank_headers;
    return Post(host, path, blank_headers);
}

void AuthenticatingProxy::Post_Async(const std::string& host,
                                     const std::string& path,
                                     const header_t& headers,
                                     const params_t& body,
                                     const std::function<void(const Response&)> handler)
{
    
}

void AuthenticatingProxy::Post_Async(const std::string& host,
                const std::string& path,
                const header_t& headers,
                const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Post_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Post_Async(const std::string& host,
                                     const std::string& path,
                                     const std::function<void(const Response&)> handler)
{
    header_t blank_headers;
    Post_Async(host, path, blank_headers, handler);
}

Response AuthenticatingProxy::Put(const std::string& host,
                                  const std::string& path,
                                  const header_t& headers,
                                  const params_t& body)
{
    Response response;
    return response;
}

Response AuthenticatingProxy::Put(const std::string& host, const std::string& path, const header_t& headers) {
    params_t blank_params;
    return Put(host, path, headers, blank_params);
}

Response AuthenticatingProxy::Put(const std::string& host, const std::string& path) {
    header_t blank_headers;
    return Put(host, path, blank_headers);
}

void AuthenticatingProxy::Put_Async(const std::string& host,
                                    const std::string& path,
                                    const header_t& headers,
                                    const params_t& body,
                                    const std::function<void(const Response&)> handler)
{
    ;
}

void AuthenticatingProxy::Put_Async(const std::string& host,
                                    const std::string& path,
                                    const header_t& headers,
                                    const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Put_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Put_Async(const std::string& host,
                                    const std::string& path,
                                    const std::function<void(const Response&)> handler)
{
    header_t blank_headers;
    Put_Async(host, path, blank_headers, handler);
}

Response AuthenticatingProxy::Delete(const std::string& host,
                                     const std::string& path,
                                     const header_t& headers,
                                     const params_t& body)
{
    Response response;
    
    return response;
}

Response AuthenticatingProxy::Delete(const std::string& host, const std::string& path, const header_t& headers) {
    params_t blank_params;
    return Delete(host, path, headers, blank_params);
}

Response AuthenticatingProxy::Delete(const std::string& host, const std::string& path)
{
    header_t blank_headers;
    return Delete(host, path, blank_headers);
}

void AuthenticatingProxy::Delete_Async(const std::string& host,
                                       const std::string& path,
                                       const header_t& headers,
                                       const params_t& body,
                                       const std::function<void(const Response&)> handler)
{
    
}

void AuthenticatingProxy::Delete_Async(const std::string& host,
                                       const std::string& path,
                                       const header_t& headers,
                                       const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Delete_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Delete_Async(const std::string& host,
                                       const std::string& path,
                                       const std::function<void(const Response&)> handler)
{
    header_t headers;
    Delete_Async(host, path, headers, handler);
}
