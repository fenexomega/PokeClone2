function ReceiveMessage(msg)

end


function Update(pos,dt)
    if isKeyDown(keys["action"]) then
        SendMessage(1)
    end
end

