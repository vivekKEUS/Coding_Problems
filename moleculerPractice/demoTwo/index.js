const { ServiceBroker } = require("moleculer");
const NATS = require("nats");
const pino = require("pino")
const broker = new ServiceBroker({
  namespace: "inventory-broker",
  nodeID: "shop-node-2",
  transporter: {
    type: "NATS",
    options: {
      url: "nats://10.1.4.196:6970",
      token: "keus-iot-platform",
    }
  },
});

broker.start().then(async () => {
  pino().info("Broker started and listening for requests...");
  pino().info(`Services are called from another node, to node: ${broker.nodeID}`)
  try {
    pino().info(await broker.call("inventory.addItem", { item: "apple", quantity: 10 }));
    pino().info(await broker.call("inventory.addItem", { item: "banana", quantity: 20 }));
    pino().info(await broker.call("inventory.addItem", { item: "orange", quantity: 15 }));
    pino().info("Fetching details for 'apple':");
    pino().info(await broker.call("inventory.getItem", { item: "apple" }));
    pino().info("Adding quantity for 'orange':");
    pino().info(await broker.call("inventory.addItem", { item: "orange", quantity: 6 }));
    pino().info("Adding quantity for 'apple':");
    pino().info(await broker.call("library.updateItem", { item: "apple", quantity: 6 }));
    pino().info("Fetching all items in the inventory:");
    pino().info(await broker.call("inventory.getAllItems"));
  } catch (err) {
    console.error("An error occurred during the workflow:", err);
  }
});