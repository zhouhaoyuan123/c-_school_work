<?php
namespace main;
echo getcwd();
require_once 'snake-game-main\vendor\autoload.php';
use Ratchet\MessageComponentInterface;
use Ratchet\ConnectionInterface;
class mserver implements MessageComponentInterface{
    private \SplObjectStorage $clients;
    private $client_groups;
    private $clientaddr;
    private $group_status;
    public function __construct() {
        $this->clients = new \SplObjectStorage;
        $this->client_groups = array();
        $this->clientaddr = array();
        $this->group_status = array();
    }
    public function onOpen(ConnectionInterface $conn) {
        $this->clients -> attach($conn);
        $this->clientaddr[$conn->resourceId] = "";
    }
    public function onMessage(ConnectionInterface $conn,$msg) {    
        $msg2 = explode(" ",$msg);
        var_dump($msg);
        if($msg == null||$msg == "" || $msg == "null") {
            return;
        }
        if($msg2[0] == "create") {
            if(is_null($this->client_groups[$msg2[1]])) {
                $this->client_groups[$msg2[1]][] = $conn;
                $this->clientaddr[$conn->resourceId] = $msg2[1];
                $this->group_status[$msg2[1]] = "wait";
                $tmp = $msg2[1];
                $conn->send("ok $tmp ");
                return;
            }//bug
            if(count($this->client_groups[$msg2[1]]) == 0) {
                $this->client_groups[$msg2[1]][] = $conn;
                $this->clientaddr[$conn->resourceId] = $msg2[1];
                $this->group_status[$msg2[1]] = "wait";
                $tmp = $msg2[1];
                $conn->send("ok $tmp");
            }
            else {
                $conn->send("acreated");
            }
        }
        else if($msg2[0] == "join") {
            if(is_null($this->client_groups[$msg2[1]])) {
                $conn->send("ngame");
                return;
            }
             if( $this->clientaddr[$conn->resourceId] != ""||count($this->client_groups)==3 || $this->group_status[$this->clientaddr[$conn->resourceId]] != "wait") {
                 $conn->send("ngame");
             }
             else {
                $this->client_groups[$msg2[1]][] = $conn;
                $tmp = $msg2[1];
                $this->clientaddr[$conn->resourceId] = $msg2[1];
                foreach ($this->client_groups[$this->clientaddr[$conn->resourceId]] as $client) {
                    //var_dump($client);
                    if($client !== $conn) {
                        $client->send("newjoin ".count($this->client_groups[$this->clientaddr[$conn->resourceId]]));
                    }
                }    
                $conn->send("ok $tmp");
            }
        }
        else if($msg2[0] == "start") {
            if($this->clientaddr[$conn->resourceId] == "") {
                $conn->send("e");
                return;
            }
            if($this->client_groups[$this->clientaddr[$conn->resourceId]][0] !== $conn) {
                $conn->send("e");
            }
            else {
                $this->group_status[$this->clientaddr[$conn->resourceId]] = "start";
                foreach ($this->client_groups[$this->clientaddr[$conn->resourceId]] as $client) {
                    //var_dump($client);
                    $client->send("start");
                }    
            }
        }
        else if($msg2[0] == "num") {
            if($this->clientaddr[$conn->resourceId] == "") {
                var_dump($this->clientaddr[$conn->resourceId]);
                $conn->send("e");
                return;
            }
            $conn->send(count($this->client_groups[$this->clientaddr[$conn->resourceId]]));
        }
        else { 
            if($this->clientaddr[$conn->resourceId] == "" || $this->group_status[$this->clientaddr[$conn->resourceId]] != "start") {
                $conn->send("e");
                echo "e";
                return;
            }
            $i = 1;
            foreach ($this->client_groups[$this->clientaddr[$conn->resourceId]] as $client) {
                if($client !== $conn) {
                    //var_dump($client);
                    $client->send("$i"." ".$msg);
                }
                $i++;
            }    
        }
        
    }
    public function onClose(ConnectionInterface $conn) {
        $i = 1;
        if($this->clientaddr[$conn->resourceId] == "") {
            unset($this->clientaddr[$conn->resourceId]);
            return;
        }
        foreach ($this->client_groups[$this->clientaddr[$conn->resourceId]] as $client) {
            if($client->resourceId == $conn->resourceId) {
                unset($this->client_groups[$this->clientaddr[$conn->resourceId][$i]]);
                break;
            }
            $i++;
        } 
        if(count($this->client_groups[$this->clientaddr[$conn->resourceId]]) == 0) {
            unset($this->client_groups[$this->clientaddr[$conn->resourceId]]);
            unset($this->group_status[$this->clientaddr[$conn->resourceId]]);
        }
        else {
            foreach ($this->client_groups[$this->clientaddr[$conn->resourceId]] as $client) {
                //var_dump($client);
                $client->send($i." "."die");
            }    
        }   
        $this->clientaddr[$conn->resourceId] = "";
        unset($this->clientaddr[$conn->resourceId]);
        $this->clients->detach($conn);
    }
    public function onError(ConnectionInterface $conn,\Exception $e) {
        $i = 1;
        if($this->clientaddr[$conn->resourceId] == "") {
            unset($this->clientaddr[$conn->resourceId]);
            return;
        }
        foreach ($this->client_groups[$this->clientaddr[$conn->resourceId]] as $client) {
            if($client->resourceId == $conn->resourceId) {
                unset($this->client_groups[$this->clientaddr[$conn->resourceId][$i]]);
                break;
            }
            $i++;
        } 
        if(count($this->client_groups[$this->clientaddr[$conn->resourceId]]) == 0) {
            unset($this->client_groups[$this->clientaddr[$conn->resourceId]]);
            unset($this->group_status[$this->clientaddr[$conn->resourceId]]);
        }      
        else {
            foreach ($this->client_groups[$this->clientaddr[$conn->resourceId]] as $client) {
                //var_dump($client);
                $client->send($i." "."die");
            }    
        }
        $this->clientaddr[$conn->resourceId] = "";
        unset($this->clientaddr[$conn->resourceId]);
        $this->clients->detach($conn);
        $conn->close();
    }
}
?>