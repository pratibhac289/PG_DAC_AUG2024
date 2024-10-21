package shopping_cart;

public class Product {
    private String productName;
    private double price;
    private String description;

    public Product(String productName, double price, String description) {
        this.productName = productName;
        this.price = price;
        this.description = description;
    }

    public String getProductName() {
        return productName;
    }

    public void show() {
        System.out.println("--- Product Details ---");
        System.out.println("Product Name: " + productName);
        System.out.println("Price: $" + price);
        System.out.println("Description: " + description);
    }
}
