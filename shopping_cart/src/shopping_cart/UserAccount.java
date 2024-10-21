package shopping_cart;

import java.util.Scanner;

class UserAccount {
    public String username;
    public String password;
    public String email;
    private ShoppingCart cart;

    Scanner sc = new Scanner(System.in);

    // Constructor to initialize user details and shopping cart
    public UserAccount(String username, String password, String email) {
        this.username = username;
        this.password = password;
        this.email = email;
        this.cart = new ShoppingCart();  // Initialize the shopping cart
    }

    // Method to accept user input
    public void acceptInfo() {
        System.out.println("Enter user name:");
        this.username = sc.nextLine();  
        System.out.println("Enter password:");
        this.password = sc.nextLine();  

        System.out.println("Enter user email ID:");
        this.email = sc.nextLine();  
    }

    // Method to display user information
    public void show() {
        System.out.println("\n--- User Details ---");
        System.out.println("Username: " + this.username);
        System.out.println("Password: " + this.password);
        System.out.println("Email: " + this.email);
    }

    public ShoppingCart getCart() {
        return cart;  // Return the shopping cart for the user
    }
}
