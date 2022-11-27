## Devcontainer.json

A [devcontainer.json](https://devcontainers.github.io/implementors/json_reference/) file in your project tells tools and services that support the dev container spec how to access (or create) a development container with a well-defined tool and runtime stack. It follows the JSON with Comments (jsonc) format.

The focus of devcontainer.json is to describe how to enrich a container for the purposes of development rather than acting as a multi-container orchestrator format. Instead, container orchestrator formats can be referenced when needed to manage multiple containers and their lifecycles. Today, devcontainer.json includes scenario specific properties for working without a container orchestrator (by directly referencing an image or Dockerfile) and for using Docker Compose as a simple multi-container orchestrator.

### VSCODE

A devcontainer.json file in your project tells Visual Studio Code how to access (or create) a development container with a well-defined tool and runtime stack. It's currently supported by the [Remote - Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension.

Use the Remote-Containers: Reopen in Container command from the Command Palette (F1, Ctrl+Shift+P).
VSCode will open a container created from DockerFile and prepare all new VSCode workspace with listed extensions, default settings, workspace mounting, etc. [Read](https://code.visualstudio.com/docs/remote/create-dev-container) more of creating a development container.
