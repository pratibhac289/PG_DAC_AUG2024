package shopping_cart;

import java.util.ArrayList;

public class ShoppingCart {
    private ArrayList<Product> cartItems = new ArrayList<>();

    public void addProduct(Product product) {
        cartItems.add(product);
        System.out.println(product.getProductName() + " has been added to your cart.");
    }

    public void viewCart() {
        if (cartItems.isEmpty()) {
            System.out.println("Your cart is empty.");
        } else {
            System.out.println("\n--- Your Shopping Cart ---");
            for (Product p : cartItems) {
                p.show();
            }
        }
    }
    public void removeProduct(String productName) {
        boolean productFound = false;

        for (Product p : cartItems) {
            if (p.getProductName().equalsIgnoreCase(productName)) {
                cartItems.remove(p);
                System.out.println(productName + " has been removed from your cart.");
                productFound = true;
                break; // Break the loop once the product is found and removed
            }
        }

        if (!productFound) {
            System.out.println("Product not found in your cart.");
        }
    }
}
