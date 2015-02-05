math.randomseed(os.time())
x = 0

function Update(obj,dt)
    acc = obj["acc"]
    acc["x"] = 0; acc["y"] = 0

    if x >= 0.5 then
        number = math.random(5) - 1;
        x = 0
    end

    if number == 0 then
            acc["x"] = -1
    elseif number == 1 then
            acc["x"] =  1
    elseif number == 2 then
            acc["y"] = -1
    elseif number == 3 then
            acc["y"] =  1
    end

    x = x + dt

end
