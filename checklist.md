# What do we want to build ? 
- "micro" web framework.


### 1. **HTTP Server** (Core)
   - **Purpose**: The foundation of any web framework is the ability to handle HTTP requests and send HTTP responses.
   - **Implementation**:
     - Use libraries like **Boost.Asio** or **libuv** for asynchronous network communication.
     - Implement a basic HTTP server that can listen for incoming connections, parse HTTP requests, and send back HTTP responses.
     - Implement basic HTTP methods such as `GET`, `POST`, `PUT`, and `DELETE`.

### 2. **Routing**
   - **Purpose**: Routing maps incoming HTTP requests to specific functions or handlers based on URL patterns.
   - **Implementation**:
     - Define routes with URL patterns and associate them with specific handler functions (controllers).
     - Implement dynamic route handling, where parts of the URL can be captured as parameters (e.g., `/user/{id}`).
     - Support HTTP method-based routing (`GET`, `POST`, etc.).

### 3. **Request and Response Handling**
   - **Purpose**: The framework needs to provide an interface to interact with incoming requests and outgoing responses.
   - **Implementation**:
     - **Request**: Parse headers, URL parameters, query parameters, body data, and cookies from the HTTP request.
     - **Response**: Provide mechanisms to construct HTTP responses, set status codes, add headers, and send body content (e.g., HTML, JSON).
     - Manage request headers, cookies, and form data parsing.
     - Support JSON handling for APIs and parsing form data (e.g., `application/x-www-form-urlencoded` and `multipart/form-data`).

### 4. **Middleware Support**
   - **Purpose**: Middleware allows you to add pre- and post-processing logic for requests and responses, such as logging, authentication, and error handling.
   - **Implementation**:
     - Implement a middleware stack where each piece of middleware can modify the request before it reaches the route handler or the response before it is sent to the client.
     - Common middleware: Authentication, logging, CORS (Cross-Origin Resource Sharing), and static file serving.

### 5. **Template Rendering**
   - **Purpose**: For dynamic content generation, your framework will need a templating engine to inject variables into HTML templates.
   - **Implementation**:
     - Develop a templating system that can take an HTML file and substitute variables or logic.
     - You can implement simple templating syntax (e.g., `{{ variable }}` or `{{ if condition }}`) or integrate with an existing C++ templating library.
     - Make sure the template system is flexible and extensible.

### 6. **Session Management**
   - **Purpose**: Web frameworks often need to manage user sessions to persist user state across requests.
   - **Implementation**:
     - Implement server-side session management using cookies and session storage (e.g., UUID-based session identifiers stored in memory or in a database).
     - Ensure the framework can manage session data securely and handle session expiration.

### 7. **Routing Context / Controllers**
   - **Purpose**: Organize the business logic of the application in a clean and modular way using controllers and context.
   - **Implementation**:
     - Allow controllers to handle routes. For example, you could have a `UserController` with methods for handling routes like `/users` or `/users/{id}`.
     - Make routing functions (or methods) more organized by associating them with specific classes or files.

### 8. **Error Handling**
   - **Purpose**: Gracefully handle and return appropriate error messages or status codes for various failure scenarios.
   - **Implementation**:
     - Implement custom error pages for common HTTP errors (e.g., 404 Not Found, 500 Internal Server Error).
     - Allow custom error handling middleware for logging and debugging.
     - Provide exception handling to prevent the server from crashing on unexpected errors.

### 9. **Database Integration (Optional but Highly Recommended)**
   - **Purpose**: Most web applications need database support to store and retrieve data.
   - **Implementation**:
     - Integrate an Object-Relational Mapping (ORM) layer, which will allow you to interact with databases using C++ objects.
     - Alternatively, you could use raw SQL queries, but an ORM will simplify the process and provide a higher-level abstraction.
     - Support multiple databases (e.g., SQLite, MySQL, PostgreSQL) using a flexible database adapter system.

### 10. **Static File Handling**
   - **Purpose**: Serve static files such as CSS, JavaScript, and image files efficiently.
   - **Implementation**:
     - Implement a way to serve files from a directory, such as `public/` or `static/`, when requested via specific URLs (e.g., `/static/js/app.js`).
     - Support caching for static files to reduce unnecessary server load.

### 11. **Routing and URL Parameter Parsing**
   - **Purpose**: Handle URL parameters (both query parameters and path parameters) and route them to appropriate controller methods.
   - **Implementation**:
     - Parse query parameters (`?id=123&name=abc`) and path parameters (e.g., `/user/{id}`) into variables for the handler to use.

### 12. **Security Features**
   - **Purpose**: A web framework must prioritize security to avoid common web vulnerabilities.
   - **Implementation**:
     - Sanitize user inputs to avoid SQL injection, cross-site scripting (XSS), and other attacks.
     - Implement Cross-Site Request Forgery (CSRF) protection for form submissions.
     - Provide methods for secure cookie handling (e.g., HttpOnly, SameSite attributes).

### 13. **Authentication and Authorization**
   - **Purpose**: Implement authentication and role-based access control (RBAC).
   - **Implementation**:
     - Allow users to log in and authenticate via sessions or tokens (JWT, OAuth, etc.).
     - Ensure route protection based on roles and permissions (e.g., admin-only routes).

### 14. **API Support (Optional)**
   - **Purpose**: If you're aiming for Zephyr to support RESTful APIs or GraphQL, implement routes to accept and return JSON.
   - **Implementation**:
     - Implement API-specific features like content negotiation, response formatting (JSON/XML), and pagination for lists of items.
     - Support for API authentication (e.g., via API keys or JWT).

### 15. **Logging and Monitoring**
   - **Purpose**: Track system performance, request logs, and errors.
   - **Implementation**:
     - Implement a logging system for keeping track of requests, errors, and any other relevant information.
     - Provide different log levels (e.g., info, warn, error, debug).
     - Allow log output to be written to files or monitored in real-time.

### 16. **Configuration Management**
   - **Purpose**: Handle configuration settings like database connection strings, server ports, and debug flags.
   - **Implementation**:
     - Provide an easy way to load and access configuration settings from environment variables, config files, or directly in code.

### Final Thoughts:
Starting with the **basic HTTP server** and **routing** will give you the foundation to expand on. Afterward, gradually implement more complex features like session management, templating, and authentication. Focus on modular design so that each part of Zephyr can be easily replaced, extended, or improved as you progress.
