//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 



//Ceasor cipher
#include "server.h"

Define_Module(Server);

void Server::initialize()
{
    // TODO - Generated method body
}

void Server::handleMessage(cMessage *msg)
{

    cGate *arrivalGate=msg->getArrivalGate();
    if(arrivalGate==gate("in1"))
    {
        std::string plaintext=msg->getFullName();
        int key=2;
        int size=plaintext.size();
        char encrypt[size];
        for(int i=0;i<size;i++)
        {
            char ch = ((plaintext[i]-'a'+2)%26)+'a';
            encrypt[i] = ch;
        }
        cMessage *msgs= new cMessage(encrypt);
                send(msgs,"out2");
    }
}

//Reverse a string
    // TODO - Generated method body
    /*cGate *arrivalGate=msg->getArrivalGate();


    if(arrivalGate==gate("in1")
    {
    std::string mes=msg->getFullName();
    char revString[mes.size()];
    int max=mes.size()-1;
    for(int i=0;i<mes.size();i++)
    {
        revString[max--]=mes.at(i);
    }
    cMessage *msgs=new cMessage(revString);
    send(msgs,"out2");*/
    //} if ending
