package com.room.roomcreator;

import java.util.List;

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

import com.room.roomcreator.Floor.FloorType;
import com.room.roomcreator.Wall.WallType;

@RestController

public class RoomRestController {

    private Room game;
    private InteriorDesign interiorDesign;

    @GetMapping("/") 
    public String instructions() {
        return "************** HUONEEN RAKENTAMISPELI **************<br><br>\n\n" +

        "----- (Info) Peli selitettynä <br>\n" +
        "-------------- <br>\n" +
        "-------------- Kun aloitat rakentamisen, niin anna ensin huoneen mitat metreissä sekä huoneen rakentamiseen käytössä oleva budjetti. <br>\n" +
        "-------------- Peli laskee mittojen perusteella huoneen pinta-alan ja voit aloittaa huoneesi materiaalivalintojen tekemisen. <br>\n" +
        "-------------- Voit tarvittaessa muokata sisustusvalintojasi. <br>\n" + 
        "-------------- Käytettävissä oleva budjetti vähenee sisustusvalintojesi edetessä. <br>\n" +
        "-------------- <br>\n" +
        "-------------- Rakentamisen iloa! <br><br>\n\n" +

        "************** KOMENNOT **************<br><br>\n\n" +
        
        "<br>\n **** POST <br>\n" +
        "-------------- Aloita peli kutsumalla: /start <br>\n" +
        "------------------- Anna tiedot: width , length , height , budget <br>\n" +
        "<br>\n **** GET <br>\n" +
        "-------------- Kutsu huoneen tila: /room <br>\n" +
        "-------------- Kutsu budjetti: /budget <br>\n" +
        "-------------- Kutsu seinien tila: /walls <br>\n" +
        "-------------- Kutsu lattian tila: /floor <br>\n" +
        "-------------- Lista valittavista seinätehosteista: /wall-types <br>\n" +
        "-------------- Lista valittavista lattiamateriaaleista: /floor-types <br>\n" +
        "<br>\n **** PUT <br>\n" +
        "-------------- Vaihda seinien tehosteita: /walls/id ja type, jossa seinän id välillä 0-3 <br>\n" +
        "-------------- Valittavat tehosteet ja materiaalit tiivistetysti: <br>\n" +
        "------------------- DRYWALL , mikä on oletuksena <br>\n" +
        "------------------- PAINT1 - PAINT7 <br>\n" + 
        "------------------- WALLPAPER1 - WALLPAPER5 <br>\n" + 
        "-------------- Vaihda lattiaa: /floor <br>\n" +
        "------------------- BASEFLOOR , mikä on oletuksena <br>\n" +
        "------------------- LAMINATE1 - LAMINATE5 <br>\n" + 
        "------------------- WOOD1 - WOOD5 <br>\n" + 
        "------------------- TILE1 - TILE7 <br><br>\n\n" +

        "-------------- Tekaisin tälle myös robottiajon <br>\n" +
        "-------------- siinä luodaan huone, vaihdetaan vähän materiaaleja ja seurataan budjettia suhteessa niihin <br>\n" +
        "------------------- Robotti (spring-robot.robot) on ajettavissa polusta: roomcreator/src/test/resources";
    }
    
    @PostMapping("/start")
    public String startGame(@RequestBody StartGameRequest request) {
        this.game = new Room(request.width(), request.length(), request.height(), request.budget());
        this.interiorDesign = new InteriorDesign(game, request.budget()); 

        return "Huone alustettu, koko" + game.getWidth() * game.getLength() + " m2, huonekorkeus: " + game.getHeight() + " m, ja budjetilla " + interiorDesign.getBudget() + " €.";
    }

    @GetMapping("/room-area")
    public double getRoomArea() {
        return game.getArea();
    }

    @GetMapping("/budget")
    public double getBudget() {
        return interiorDesign.getBudget() - interiorDesign.getRoom().getCost();
    }

    @GetMapping("/walls")
    public List <Wall> getWalls() {
        return interiorDesign.getRoom().getWalls();
    }

    @GetMapping("/floor") 
    public Floor getFloor() {
        return interiorDesign.getRoom().getFloor();
    }

    @GetMapping("/room")
    public Room getRoom() {
        return interiorDesign.getRoom(); 
    }

    @PutMapping("/walls/{id}") 
    public void updateWall(@PathVariable Integer id, @RequestBody String type) {
        WallType newType = WallType.valueOf(type.trim());
        Wall updatedWall = new Wall(interiorDesign.getRoom().getWalls().get(id).getArea(), newType);
        if (checkBudget(interiorDesign.getRoom().getWalls().get(id), updatedWall)) {
            interiorDesign.getRoom().updateWall(id, newType);
        } else {
            throw new ResponseStatusException(HttpStatus.NOT_ACCEPTABLE, "Budjetti ei riitä tähän sisustusvalintaan");
        }
    }

    @PutMapping("/floor") 
    public void updateFloor(@RequestBody String type) {
        FloorType newType = FloorType.valueOf(type.trim());
        Floor updatedFloor = new Floor(newType);
        if (checkBudget(interiorDesign.getRoom().getFloor(), updatedFloor)) {
            interiorDesign.getRoom().updateFloor(newType);
        } else {
            throw new ResponseStatusException(HttpStatus.NOT_ACCEPTABLE, "Budjetti ei riitä tähän sisustusvalintaan");
        }
    }

    @GetMapping("/walls/types")
    public List<WallType> getWallTypes() {
        return interiorDesign.getAvailableWallTypes();
    }

    @GetMapping("/floor/types")
    public List<FloorType> getFloorTypes() {
        return interiorDesign.getAvailableFloorTypes();
    }

    private boolean checkBudget(DecorationItem old , DecorationItem updated) {
        double budget = interiorDesign.getBudget();
        budget -= interiorDesign.getRoom().getCost();

        double delta = updated.getCost(interiorDesign.getRoom()) - old.getCost(interiorDesign.getRoom());
        budget -= delta;
        return budget >= 0;
    }

}