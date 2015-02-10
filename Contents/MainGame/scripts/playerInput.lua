acceleration = 1


function ReceiveMessage(msg)

end


function Update(obj,dt)
    acc = obj["acc"]
    acc["x"] = 0 ; acc["y"] = 0

    if isKeyPressed(keys["up"]) then
        acc["y"] = -acceleration
    elseif isKeyPressed(keys["down"]) then
        acc["y"] = acceleration
    elseif isKeyPressed(keys["left"]) then
        acc["x"] = acceleration
    elseif isKeyPressed(keys["right"]) then
        acc["x"] = -acceleration
    end

end
