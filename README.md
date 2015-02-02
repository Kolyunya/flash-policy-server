# Flash policy file server

## Description

This is a crossplatform Qt5 implementation of the Adobe Flash policy file server.

The application is quite flexible and configurable. You can configure which hosts would be allowed to connect to the server and to which ports; which network interface and port the server will listen to; how many threads the thread pool would be allowed to create and after what duration the threads will be deleted.

## Usage

* Compile the `FlashPolicyServer.pro` project.
* Put `flash-policy-server.ini` and `flash-policy-server.xml` files near the project executable.
* Alter application configuration if needed (configuration defaults have sensible values already).
* Run the application executable file.
* Connect to the server from your Flash clients.
