cmake_minimum_required(VERSION 3.0)

project(GatewayServer)

#link_libraries(profiler)

gen_server("Base" "GatewayServer")

set(SERVER_ID  23)
set(TARS_WEB_HOST http://10.100.5.55:3000)
set(TARS_WEB_TICKET  362539a5fe092d31859dcf9131b6b1a0057bcb49)



add_custom_command(
        TARGET "GatewayServer"
        PRE_BUILD
        COMMAND echo "stop server ${SERVER_ID}"
        && curl --location --request POST '${TARS_WEB_HOST}/api/add_task?ticket=${TARS_WEB_TICKET}'
        --header 'Content-Type: application/json'
        --data '{"serial": true,"items": [{"server_id":"${SERVER_ID}","command":"stop","parameters": {}}]}'
        && echo ""
        && sleep 2
)

add_custom_command(
        TARGET "GatewayServer"
        POST_BUILD
        COMMAND echo "restart server ${SERVER_ID}"
        && curl --location --request POST '${TARS_WEB_HOST}/api/add_task?ticket=${TARS_WEB_TICKET}'
        --header 'Content-Type: application/json'
        --data '{"serial": true,"items": [{"server_id":"${SERVER_ID}","command":"restart","parameters": {}}]}'
        && echo ""
)

target_link_libraries(GatewayServer mysqlclient dl amqpcpp uv)
