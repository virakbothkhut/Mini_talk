# Mini_talk
Mini talk project is about the communication between a client and sever.

- The sever must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
      - The sever PID.
      - The string to end.

- The client must send the string passed as a parameter to the sever. Once the string has been recieved, the server must print it.

  The sever has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.

  Your sever should be able to recieve strings from several clients in a row without needing to restart.

  The communication between your client, and your sever has to be done only using UNIX signals.

  You can only use these two signal: SIGUSR1 and SIGUSR2.
