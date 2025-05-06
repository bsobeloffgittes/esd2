import tornado.ioloop
import tornado.web
import tornado.websocket
import tornado.httpserver
import os

# Track all connected browser clients
clients = set()

class MainHandler(tornado.web.RequestHandler):
    def get(self):
        self.render("index.html")

class EchoWebSocket(tornado.websocket.WebSocketHandler):
    def check_origin(self, origin):
        return True  # Allow connections from any origin

    def open(self):
        print("Browser connected")
        clients.add(self)

    def on_message(self, message):
        print(f"Browser said: {message}")
        self.write_message(f"Echo: {message}")

    def on_close(self):
        print("Browser disconnected")
        clients.discard(self)

class EchoWebSocketESP32(tornado.websocket.WebSocketHandler):
    def check_origin(self, origin):
        return True  # Allow ESP32 to connect regardless of origin

    def open(self):
        print("ESP32 connected from", self.request.remote_ip)

    def on_message(self, message):
        print(f"Received message from ESP32: {message}")

        # Broadcast to all connected browsers
        for client in clients:
            client.write_message(f"[Encoder] {message}")

    def on_close(self):
        print("ESP32 disconnected")

def make_app():
    return tornado.web.Application([
        (r"/", MainHandler),
        (r"/ws", EchoWebSocket),
        (r"/ws_esp32", EchoWebSocketESP32),
    ], template_path=os.path.join(os.path.dirname(__file__), "templates"))

if __name__ == "__main__":
    app = make_app()
    server = tornado.httpserver.HTTPServer(app)
    server.listen(8888)
    print("Server running at http://localhost:8888")
    tornado.ioloop.IOLoop.current().start()
