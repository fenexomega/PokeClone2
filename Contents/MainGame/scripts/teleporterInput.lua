require "Contents/MainGame/scripts/messages"

function ReceiveMessage(msg)
    if msg == PLAYER_NEAR then
        if isKeyDown(keys["action"]) then
             SendMessage(CHANGE_MAP)
        end
    end
end

function Update(pos,dt)

end

