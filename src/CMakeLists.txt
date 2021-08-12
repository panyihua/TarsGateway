cmake_minimum_required(VERSION 2.8)

project(GatewayServer)

#link_libraries(profiler)

gen_server("Base" "GatewayServer")

add_custom_command(
        TARGET "GatewayServer"
        PRE_BUILD
        COMMAND echo "stop server"
        && curl --location --request POST 'http://10.100.5.55:3000/api/add_task?ticket=362539a5fe092d31859dcf9131b6b1a0057bcb49'
        --header 'Content-Type: application/json'
        --data '{"serial": true,"items": [{"server_id":"23","command":"stop","parameters": {}}]}'
        && echo ""
        && sleep 2
)

add_custom_command(
        TARGET "GatewayServer"
        POST_BUILD
        COMMAND echo "restart server"
        && curl --location --request POST 'http://10.100.5.55:3000/api/add_task?ticket=362539a5fe092d31859dcf9131b6b1a0057bcb49'
        --header 'Content-Type: application/json'
        --data '{"serial": true,"items": [{"server_id":"23","command":"restart","parameters": {}}]}'
        && echo ""
)

target_link_libraries(GatewayServer mysqlclient dl amqpcpp uv)
