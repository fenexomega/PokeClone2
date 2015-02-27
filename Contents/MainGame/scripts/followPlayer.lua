acceleration_init = 1
circle_radius = 10

function ReceiveMessage(msg)

end


function Update(obj,dt)
    acc = obj["acc"]
    acc.x = 0 ; acc.y = 0
    circle = {center = {x = obj.rect.x + 16, y = obj.rect.y + 16},radius = circle_radius }

    print(circle.center.x)
    print(player.rect.x)

-- BUG Essa colisão não funciona
    if isCollidingRC(player.rect,circle) then
        print("Colidindo")
        acc.x = -1
    end



end
