
function Update(obj)
    acc = obj["acc"]
    acc["x"] = 0 ; acc["y"] = 0
    if isKeyPressed(keys["up"]) then
        acc["y"] = -1
    elseif isKeyPressed(keys["down"]) then
        acc["y"] = 1
    elseif isKeyPressed(keys["left"]) then
        acc["x"] = 1
    elseif isKeyPressed(keys["right"]) then
        acc["x"] = -1
    end
end
