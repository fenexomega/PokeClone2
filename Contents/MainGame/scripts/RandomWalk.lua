math.randomseed(os.time())
waitTime = math.random()
x = 0

function Update(obj,dt)
    acc = obj["acc"]
    acc["x"] = 0; acc["y"] = 0

    if not onScreen(obj["rect"]) then
        print(obj["rect"]["w"])
        print("Não está na tela")
        return
    end

    if x >= waitTime then
        number = math.random(8) - 1;
        waitTime = math.random()
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
