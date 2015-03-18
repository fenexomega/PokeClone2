math.randomseed(os.time())
waitTime = math.random()
x = 0
acceleration = 1

function ReceiveMessage(msg)

end

function Update(obj,dt)
    acc = obj["acc"]
    acc.x = 0; acc.y = 0

    if not onScreen(obj["rect"]) then
        return
    end

    if x >= waitTime then
        number = math.random(8) - 1;
        waitTime = math.random()
        x = 0
    end

    if number == 0 then
            acc.x = -acceleration
    elseif number == acceleration then
            acc.x =  acceleration
    elseif number == 2 then
            acc.y = -acceleration
    elseif number == 3 then
            acc.y =  acceleration
    end

    x = x + dt

end
