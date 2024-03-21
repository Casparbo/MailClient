# Custom mail client
For this project I want to create a mail client in C. It will be command line based and use text files for storing and creating mails.
Under no circumstances will this client to anything except send and receive mails, no calendar, no chat, nothing else.

## Architecture
### HTTP Client
- Creates a connection to a server
- returns a struct with session information (port and other stuff)
- allows to send messages
# Functions
1. Create Connection: Takes Target Address, Returns Connection Struct
2. Send Message: Takes Connection Struct and Message, Returns Response
3. Close Connection: Takes Connection Struct, Returns Success
### POP3/IMAP Client
- Uses HTTP Client
- Retrieves Mail from server
- deploys Mails as files in a directory
### SMTP Client
- Takes text file as input
- adds headers such as recipient and sender
- Uses HTTP Client to send Mail to server

## Binaries
Binaries need to go into the _/bin_ folder.
