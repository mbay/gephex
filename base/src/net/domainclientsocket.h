/* This source file is a part of the GePhex Project.

 Copyright (C) 2001-2004

 Georg Seidel <georg@gephex.org> 
 Martin Bayer <martin@gephex.org> 
 Phillip Promesberger <coma@gephex.org>
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.*/

#ifndef INCLUDED_DOMAIN_CLIENT_SOCKET_H
#define INCLUDED_DOMAIN_CLIENT_SOCKET_H

#include "iclientsocket.h"

namespace net
{

  /**
   * Die Klasse Netstream kapselt die gesamte Netzwerkfunktionalität.
   * Sie ist dafür ausgelegt nichtblockierend zu arbeiten (-> keine Threads).
   * Sie kann prinzipiell in zwei Modi arbeiten: serverMode und clientMode.
   * Im ServerMode wartet sie an einem bestimmten Port auf connections.
   * Im Clientmode ist es möglich mit connectTo zu einem anderen Rechner
   * in Verbindung zu treten.
   */
  class DomainClientSocket : public IClientSocket
  {

  public:
    explicit DomainClientSocket(int localPort = 0);
    virtual ~DomainClientSocket();

    /**
     * Connects do another domainsocket.
     * @param basePath the prefix of the file that is accepting the
     *     connection, for example "/tmp/server_socket_".
     * @param remotePort the port is appended to the basePath
     *     to complete the filename
     */
    ISocket* connect(const std::string& basePath,
		     int remotePort) throw(std::runtime_error);

  private:
    int m_socket;
    int m_localPort;
  };

}

#endif
