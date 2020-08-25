const micro = require("micro")
const handler = require("serve-handler")

const { PORT = 3000 } = process.env

const main = async () => {
  const server = micro((req, res) =>
    handler(req, res, {
      public: "public",
    })
  )

  server.listen(PORT)
}

main()
  .then(() => {
    console.log(`Server ready: http://localhost:${PORT}`)
  })
  .catch((e) => {
    console.error(`Server not started due to error: ${e}`)
  })
