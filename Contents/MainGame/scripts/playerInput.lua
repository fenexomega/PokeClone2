acceleration_init = 1


function ReceiveMessage(msg)

end


function Update(obj,dt)
    acc = obj["acc"]
    acc.x = 0 ; acc.y = 0

    acceleration = acceleration_init

    if isKeyPressed(keys["cancel"]) then
        acceleration = acceleration*2
    end


    if isKeyPressed(keys["up"]) then
        acc.y = acc.y - acceleration
	elseif isKeyPressed(keys["down"]) then
        acc.y = acc.y + acceleration
	elseif isKeyPressed(keys["left"]) then
        acc.x = acc.x + acceleration
	elseif isKeyPressed(keys["right"]) then
        acc.x = acc.x -acceleration
    end


end
