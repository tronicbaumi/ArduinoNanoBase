// template.scad


$fn=60;

// variables


// Length
length = 70+1;    // [5:1:80]
// Width
width = 50+1;    // [1:1:69]
// Height
height = 40;        // [1:1:100]
// Wall
wall = 2;     // [1:0.1:8]

//

main();


module main()
{
    
//    translate([50,0,0])cube_r(30,20,10,2);
//    
//    translate([0,50,0])rotate([90,0,0])rectTriangle(10,20,5);
//    
//    linear_extrude(12)translate([10,10,0])import("BFKDO.svg");
//    
//    translate([50,50,0])rotate([0,0,0])linear_extrude(height = 0.5)text("(c) ChB 2/2021",size = 5);
//    
//    translate([100,0,0])cylinder_r(40,12,8,3,2);
    
    difference(){
        plus();
        minus();

    }
    
    difference()
    {
        union()
        {
            translate([64.45/2,44.45/2,-height/2])rotate([0,0,0])cylinder(wall+3,8/2,8/2);
           // translate([64.45/2,44.45/2,-height/2])rotate([0,0,0])cylinder(wall+6,2.9/2,2.9/2);

            translate([64.45/2,-44.45/2,-height/2])rotate([0,0,0])cylinder(wall+3,8/2,8/2);
            //translate([64.45/2,-44.45/2,-height/2])rotate([0,0,0])cylinder(wall+6,2.9/2,2.9/2);
            
            translate([-64.45/2,44.45/2,-height/2])rotate([0,0,0])cylinder(wall+3,8/2,8/2);
            //translate([-64.45/2,44.45/2,-height/2])rotate([0,0,0])cylinder(wall+6,2.9/2,2.9/2);
            
            translate([-64.45/2,-44.45/2,-height/2])rotate([0,0,0])cylinder(wall+3,8/2,8/2);
            //translate([-64.45/2,-44.45/2,-height/2])rotate([0,0,0])cylinder(wall+6,2.9/2,2.9/2);
        }
        translate([64.45/2,44.45/2,-height/2])rotate([0,0,0])cylinder(wall+3,2.3/2,2.3/2);
        translate([-64.45/2,44.45/2,-height/2])rotate([0,0,0])cylinder(wall+3,2.3/2,2.3/2);
        translate([64.45/2,-44.45/2,-height/2])rotate([0,0,0])cylinder(wall+3,2.3/2,2.3/2);
        translate([-64.45/2,-44.45/2,-height/2])rotate([0,0,0])cylinder(wall+3,2.3/2,2.3/2);
    }

      

}




module plus()
{   
    translate([0,0,0])rotate([0,0,0])cube([length+2*wall,width+2*wall,height],true);
    
    difference()
    {
        translate([0,0,-height/2+0.5])union()
        {
            translate([0,80,0])rotate([0,0,0])cube([length+2*wall,width+2*wall,1],true);
            translate([0,80,1.5])rotate([0,0,0])cube([length,width,3],true);
        }
        
        translate([0,80,-height/2+2])rotate([0,0,0])cube([28,28,3],true);    
        translate([0,82,-height/2])rotate([0,0,0])cube([26,17,3],true); 
    }
}

module minus()
{
//    translate([0,0,12])rotate([0,0,0])cylinder(4,12/2,11.8/2);
    translate([0,0,wall])rotate([0,0,0])cube([length,width,height],true);
    
    // X3
    translate([25.2,width/2+wall,wall+3+6-height/2])rotate([90,0,0])cylinder(wall,4/2,4/2);  
    
    // X4
    translate([15.1,width/2+wall,wall+3+6-height/2])rotate([90,0,0])cylinder(wall,4/2,4/2);
    
    // USB
    translate([0.6-14/2,width/2,wall+3+13-height/2])rotate([0,0,0])cube([14,wall,6]);    
    
    // NRF
    //translate([-18,width/2+wall,wall+3+14-height/2])rotate([90,0,0])cylinder(wall,6.8/2,6.8/2); //translate([-18,width/2+wall,wall+3+14-height/2])rotate([90,0,0])cylinder(wall,9.3/2,9.3/2);
    
    translate([-18-3.4,width/2,wall+3+14-3.4-height/2])rotate([0,0,0])cube([6.8,wall,6.8]);
    translate([-18-10,width/2-1,wall+3+15-3.4-height/2])rotate([0,0,0])cube([20,wall,4]);
    
    // POT
    translate([-length/2-wall,14,wall+3+8.5-height/2])rotate([90,0,90])cylinder(wall,4/2,4/2);
    
    // Sensors
    translate([-length/2-wall,-14,wall+3+20-height/2])rotate([90,0,90])cylinder(wall,8/2,8/2);
    
    // SD
    translate([length/2,-8,wall+3+1.5-height/2])rotate([0,0,0])cube([wall,14,2.5]); 
    
    // Power
    translate([length/2,-19.5,wall+3+0.5-height/2])rotate([0,0,0])cube([wall,10,10]);
    
    // LED1
    translate([length/2,11,wall+3+1.5-height/2])rotate([90,0,90])cylinder(wall,1.5/2,1.5/2);
    
    // LED2
    translate([length/2,13.5,wall+3+1.5-height/2])rotate([90,0,90])cylinder(wall,1.5/2,1.5/2);
    
    // LED3
    translate([length/2,16,wall+3+1.5-height/2])rotate([90,0,90])cylinder(wall,1.5/2,1.5/2);
}

module cube_r(x,y,z,r)
{
    hull()
    {
        translate([r,r,r])cube([x-2*r,y-2*r,z-2*r]);
        translate([r,r,r])rotate([0,0,0])cylinder(z-2*r,r,r);
        translate([r,y-r,r])rotate([0,0,0])cylinder(z-2*r,r,r);
        translate([x-r,r,r])rotate([0,0,0])cylinder(z-2*r,r,r);
        translate([x-r,y-r,r])rotate([0,0,0])cylinder(z-2*r,r,r);
        
        translate([r,r,r])rotate([0,90,0])cylinder(x-2*r,r,r);
        translate([r,y-r,r])rotate([0,90,0])cylinder(x-2*r,r,r);
        translate([r,y-r,z-r])rotate([0,90,0])cylinder(x-2*r,r,r);
        translate([r,r,z-r])rotate([0,90,0])cylinder(x-2*r,r,r);
        
        translate([x-r,y-r,r])rotate([90,0,0])cylinder(y-2*r,r,r);
        translate([r,y-r,r])rotate([90,0,0])cylinder(y-2*r,r,r);
        translate([r,y-r,z-r])rotate([90,0,0])cylinder(y-2*r,r,r);
        translate([x-r,y-r,z-r])rotate([90,0,0])cylinder(y-2*r,r,r);
        
        translate([r,r,r])sphere(r = r);
        translate([x-r,r,r])sphere(r = r);
        translate([r,y-r,r])sphere(r = r);
        translate([x-r,y-r,r])sphere(r = r);
        
        translate([r,r,z-r])sphere(r = r);
        translate([x-r,r,z-r])sphere(r = r);
        translate([r,y-r,z-r])sphere(r = r);
        translate([x-r,y-r,z-r])sphere(r = r);
    }
}

module cylinder_r(h,r1,r2,r3,r4)
{
    hull()
    {
        translate([0,0,r3])cylinder(h-r3-r4,r1-r3,r2-r4);
        
        translate([0,0,r3])rotate_extrude(convexity = 10, $fn = 100)
            translate([r1, 0, 0])circle(r = r3, $fn = 100);
        
        translate([0,0,h-r4])rotate_extrude(convexity = 10, $fn = 100)
            translate([r2, 0, 0])circle(r = r4, $fn = 100);
    }
    
}

module rectTriangle(a,b,h)
{
linear_extrude(height = h, center = false, convexity = 10, twist = 0)
    polygon(points=[[0,0],[a,0],[0,b]]);   
}


