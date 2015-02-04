math.randomseed(os.time())
x = 0

function Update(obj)
    acc = obj["acc"]
    acc["x"] = 0; acc["y"] = 0
    if x == 0 then
        number = math.floor(math.random()*10);
        x = 20
    end
    if number == 0 then
            acc["x"] = -1
    elseif number == 1 then
            acc["x"] = 1
    elseif number == 2 then
            acc["y"] = -1
    elseif number == 3 then
            acc["y"] = 1
    end
    x = x - 1

end
