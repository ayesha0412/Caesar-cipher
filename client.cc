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

#include "client.h"

Define_Module(Client);

void Client::initialize()
{
    // TODO - Generated method body
    if(strcmp(getName(),"pc1")==0)
    {
        cMessage *msg=new cMessage("NewYork");
        send(msg,"out");
    }
}

void Client::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(strcmp(getName(),"pc2")==0)
       {
        std::string ciphertext=msg->getFullName();
                int size=ciphertext.size();
                char decrypt[size];
                for(int i=0;i<size;i++)
                {
                    char ch=((ciphertext[i]-'a'-2)%26)+'a';
                    decrypt[i]=ch;
                }
                cMessage *msgs= new cMessage(decrypt);
                send(msgs,"out");
       }
}
