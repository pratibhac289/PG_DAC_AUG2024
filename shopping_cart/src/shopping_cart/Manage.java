package shopping_cart;

import java.util.ArrayList;
import java.util.Scanner;

public class Manage {
    private ArrayList<UserAccount> userList = new ArrayList<>();  // List to store multiple users
    private ArrayList<Product> productList = new ArrayList<>(); 
    Scanner sc = new Scanner(System.in);

    public Manage() {
        // Sample products
        productList.add(new Product("Laptop", 999.99, "High-performance laptop."));
        productList.add(new Product("Smartphone", 699.99, "Latest smartphone model."));
        productList.add(new Product("Headphones", 199.99, "Noise-cancelling headphones."));
    }

    // Display menu and handle choices using switch-case
    public void displayMenu() {
        boolean exit = false;  // Flag to control the loop

        while (!exit) {
            // Display Menu Options
            System.out.println("\n--- User Account Management ---");
            System.out.println("1. Create a new User Account");
            System.out.println("2. View All User Accounts");
            System.out.println("3. View All Product List");
            System.out.println("4. Add Product to Cart");
            System.out.println("5. Remove Product from Cart");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine();  // Consume the newline

            switch (choice) {
                case 1:
                    // Create a new user account
                    UserAccount user = new UserAccount("", "", "");
                    user.acceptInfo();
                    userList.add(user);
                    System.out.println("User account created successfully!");
                    break;

                case 2:
                    // View all user accounts
                    if (userList.isEmpty()) {
                        System.out.println("No user accounts available.");
                    } else {
                        System.out.println("\n--- All User Accounts ---");
                        for (UserAccount u : userList) {
                            u.show();
                        }
                    }
                    break;

                case 3:
                    // View all product list
                    if (productList.isEmpty()) {
                        System.out.println("No products available.");
                    } else {
                        System.out.println("\n--- Product List ---");
                        for (Product p : productList) {
                            p.show();
                        }
                    }
                    break;  // Add a break statement here

                case 4:
                    // Add products to cart
                    System.out.println("Enter your username to add products to your cart:");
                    String username = sc.nextLine();
                    UserAccount currentUser = null;

                    // Find the user
                    for (UserAccount u : userList) {
                        if (u.username.equals(username)) {
                            currentUser = u;
                            break;
                        }
                    }

                    if (currentUser != null) {
                        String addMore;  // Variable to check if the user wants to add more products
                        do {
                            System.out.println("Enter the product name to add to your cart:");
                            String productName = sc.nextLine();
                            Product productToAdd = null;

                            // Find the product
                            for (Product p : productList) {
                                if (p.getProductName().equalsIgnoreCase(productName)) {
                                    productToAdd = p;
                                    break;
                                }
                            }

                            if (productToAdd != null) {
                                currentUser.getCart().addProduct(productToAdd);
                            } else {
                                System.out.println("Product not found.");
                            }

                            System.out.println("Do you want to add another product? (yes/no)");
                            addMore = sc.nextLine();
                        } while (addMore.equalsIgnoreCase("yes"));  // Continue until the user says 'no'
                    } else {
                        System.out.println("User not found.");
                    }
                    break;

                case 5:
                    // Remove product from cart
                    System.out.println("Enter your username to remove a product from your cart:");
                    username = sc.nextLine();
                    currentUser = null;

                    // Find the user
                    for (UserAccount u : userList) {
                        if (u.username.equals(username)) {
                            currentUser = u;
                            break;
                        }
                    }

                    if (currentUser != null) {
                        System.out.println("Enter the product name to remove from your cart:");
                        String productName = sc.nextLine();

                        // Attempt to remove the product from the user's cart
                        currentUser.getCart().removeProduct(productName);
                    } else {
                        System.out.println("User not found.");
                    }
                    break;

                    
                case 6:
                    // Exit the program
                    exit = true;
                    System.out.println("Exiting the program...");
                    break;

                default:
                    // Handle invalid choices
                    System.out.println("Invalid choice! Please try again.");
            }
        }
    }

    public static void main(String[] args) {
        // Create an instance of Manage to manage accounts and products
        Manage manager = new Manage();

        // Display the menu and handle user input
        manager.displayMenu();
    }
}
