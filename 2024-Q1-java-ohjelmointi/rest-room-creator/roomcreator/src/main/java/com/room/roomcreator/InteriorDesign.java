package com.room.roomcreator;

import java.util.Arrays;
import java.util.List;

import com.room.roomcreator.Floor.FloorType;
import com.room.roomcreator.Wall.WallType;

public class InteriorDesign {

    private Room room;
    private double budget;

    public InteriorDesign(Room room, double budget) {
        this.room = room;
        this.budget = budget;
    }

    public Room getRoom() {
        return this.room;
    }

    public double getBudget() {
        return this.budget;
    }

    /*public String decorateRoom (DecorationItem item) {

        if (item.getCost(room) <= budget) {
            budget -= item.getCost(room);
            return "Valittu: " + item.getName() + "hinta: " + item.getCost(room) + ", budjetista jäljellä: " + budget + "€";
        } else {
            return "Budjetti ei riitä tähän sisustusvalintaan";
        }
    }*/

    public List<WallType> getAvailableWallTypes() {
        return Arrays.asList(WallType.values());
    }

    public List<FloorType> getAvailableFloorTypes() {
        return Arrays.asList(FloorType.values());
    }

}
