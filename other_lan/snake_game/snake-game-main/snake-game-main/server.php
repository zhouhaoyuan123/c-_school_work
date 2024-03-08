<?php
require_once "src/main.php";
require_once 'vendor/autoload.php';
use Ratchet\Server\IoServer;
use Ratchet\Http\HttpServer;
use Ratchet\WebSocket\WsServer;
use main\mserver;

$server = IoServer::factory(
    new HttpServer(
        new WsServer(
            new mserver()
        )
    ),
    8082
);

$server->run();