const micro = require("micro")
const handler = require("serve-handler")

const server = micro((req, res) =>
  handler(req, res, {
    public: "public",
  })
)

server.listen(process.env.PORT || 3000)
