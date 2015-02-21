require "Contents/MainGame/scripts/messages"

function ReceiveMessage(msg)

end

function Update(pos,dt)
    if isKeyDown(keys["action"]) then
        SendMessage(PLAYER_INTERACTION)
    end
end

