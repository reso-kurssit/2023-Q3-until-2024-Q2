package com.room.roomcreator;

public class Decorate implements DecorationItem {

    private String name;
    private double cost;

    public Decorate(String name, double cost) {
        this.name = name;
        this.cost = cost;
    }

    @Override
    public double getCost(Room room) {
        return cost;
    }

    @Override
    public String getName() {
        return name;
    }
}