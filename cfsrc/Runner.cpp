#include "Runner.hpp"
Runner::Runner(Server* s){
    if(s){
        this->server = s;
    }else{
        std::cout << "Incorrect Server creation, making a default..." << std::endl;
        this->server = new Server();
    }

    while(1){
        ENetEvent event;
        /* Wait up to 1000 milliseconds for an event. */
        while (enet_host_service (server->getHost(), & event, 1000) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_CONNECT:
                printf ("A new client connected from %x:%u.\n", 
                        event.peer -> address.host,
                        event.peer -> address.port);
                /* Store any relevant client information here. */
                // event.peer ->data = `"Client information";
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
                        event.packet -> dataLength,
                        event.packet -> data,
                        event.peer -> data,
                        event.channelID);
                /* Clean up the packet now that we're done using it. */
                enet_packet_destroy (event.packet);
                
                break;
            
            case ENET_EVENT_TYPE_DISCONNECT:
                printf ("%s disconnected.\n", event.peer -> data);
                /* Reset the peer's client information. */
                event.peer -> data = NULL;
            }
        }
    }
}

