# Contributions

All contributors must first sign the [Particle Individual Contributor License Agreement (CLA)](https://part.cl/icla), which is based on the Google CLA, and provides the Particle team a license to re-distribute your contributions.

Whenever possible, please follow these guidelines for contributions:

- Keep each pull request small and focused on a single feature or bug fix.
- Familiarize yourself with the code base, and follow the formatting principles adhered to in the surrounding code.
- Wherever possible, provide unit tests for your contributions.
- If the changes have an impact application developers, then those changes should be described in the documentation.
- Ensure your code adheres to the [Style Guide](STYLE_GUIDE.md).
- Use meaningful commit messages following the [Commit Message Guidelines](#commit-message-guidelines).

## Example Pull Request Process

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/my-new-feature`
3. Make your changes following the style guide
4. Add tests for your changes
5. Commit your changes: `git commit -m "Add new feature"`
6. Push to the branch: `git push origin feature/my-new-feature`
7. Submit a pull request

## Commit Message Guidelines

Follow these conventions for commit messages:

- Use the present tense ("Add feature" not "Added feature")
- Use the imperative mood ("Move cursor to..." not "Moves cursor to...")
- Limit the first line to 72 characters or less
- Reference issues and pull requests after the first line
- Use prefixes: `feat:`, `fix:`, `docs:`, `style:`, `refactor:`, `test:`, `chore:`

**Example:**
```
feat: add support for new sensor module

- Implement driver for XYZ sensor
- Add configuration options
- Update documentation

Closes #123
```

## Pull Request Guidelines

When submitting a pull request, please adhere to the following guidelines:

- **Descriptive Title**: Use a clear and concise title that summarizes the changes.
- **Detailed Description**: Provide a detailed description of the changes, including the problem being solved and the approach taken.
- **Linked Issues**: Reference any related issues or pull requests using keywords like `Closes #123`.
- **Testing**: Include details about how the changes were tested and any relevant test cases.
- **Documentation**: Update relevant documentation to reflect the changes.
- **Commit Messages**: Follow the commit message guidelines outlined above.

By following these guidelines, you help ensure a smooth review process and maintain the quality of the codebase.

## Code Review Guidelines

When reviewing pull requests, please consider:

- **Functionality**: Does the code work as intended?
- **Style**: Does it follow the project's style guide?
- **Tests**: Are there adequate tests for the changes?
- **Documentation**: Are the changes properly documented?
- **Performance**: Could there be any performance implications?
- **Security**: Are there any security concerns?

Be constructive and respectful in your feedback. 


# Tests and Documentation

Any changes that affect firmware application developers, such as a new class or API, or change in existing behavior should have an accompanying PR to the `spark/docs` repo describing the changes. This ensures the documentation is kept up to date with changes to the firmware.

New firmware APIs should have an API test. These are found in the `user/tests/wiring/api` folder. see [Building Platform Tests](https://github.com/spark/firmware/blob/develop/user/tests/readme.md#building-platform-tests).

New functionality should also have a corresponding unit test. These are found in `user/tests/wiring/no_fixture` when they do not require any additional test fixture beyond the device itself. Tests requiring a hardware fixture are found in the varoius subdirecotires. If the hardware fixture you need is already present, then feel free to add more tests to that. When the hardware fixture is not present, simply create a new directory, following the pattern of the existing tests (and by copying application.cpp from an existing     test.   )

## Reorganizing Test Cases

To improve maintainability, the `test/` directory has been reorganized. Contributors should:

1. Place unit tests in the `test/unit/` directory.
2. Place integration tests in the `test/integration/` directory.
3. Place performance tests in the `test/performance/` directory.

Ensure that new test cases follow this structure and are properly documented.

# Changes to Functions, Structures and Dynalib Tables

With dynamic linking, APIs must remain backwards compatible at the ABI level, since newer code may be called by older clients. 

Here are some guidelines to follow to ensure compatibility for structs and functions used in a dynamic interface:

- Do not add or remove arguments to the function signature. If the function has
a final reserved `void*` this may be changed to name a struct that is optionally passed to the function. The struct should have it's size as the first member. If the function already has such a struct, no changes other than renaming fields (which doesn't affect the binary) or adding fields at the end of the struct are allowed.

- Tables of dyanmic entrypoints should not be changed, in particular, the order
of the `DYNALIB_FN` entries must remain unchanged. New entries can be added at the end. Ensure that the function can evolve by including a `void*` reserved parameter as the last parameter. 




# Subtrees

The repository imports content from other repos via git subtrees. These are the current
subtrees:

- communication/lib/mbedtls

(you can find an up-to-date list by running git log | grep git-subtree-dir | awk '{ print $2 }')

When making commits, do not mix commits that span subtrees. E.g. a commit that posts
changes to files in communication/lib/libcoap and communication/src should be avoided.
No real harm is done, but the commit messages can be confusing since those files outside the subtree
will be removed when the subtree is pushed to the upstream repo.

To avoid any issues with subtres, it's simplest to make all changes to the upstream repo via
PRs from a separate working copy, just as you would with any regular repo. Then pull these changes
into the subtree in this repo.

### Adding Code Examples
- When adding a new code example, ensure it is placed in the appropriate section of `docs/code_examples.md`.
- Verify that the example is functional and adheres to the style guide.

### Adding Troubleshooting Guides
- When adding a new troubleshooting guide, ensure it is placed in the appropriate section of `docs/troubleshooting.md`.
- Verify that the guide is accurate and adheres to the style guide.

### Adding Third-Party Libraries
- Place new third-party libraries in the appropriate subdirectory under `third_party/`.
- Ensure the library is properly documented and follows the new directory structure guidelines.

### Adding Logging API Examples

When adding examples for the new logging API, follow these steps:

1. **Create a New Example**: Write a concise and functional example demonstrating the logging API's usage.
2. **Place in Documentation**: Add the example to the `docs/logging.md` file under the "Examples" section.
3. **Verify Functionality**: Ensure the example is functional and adheres to the project's style guide.
4. **Reference in PR**: When submitting a pull request, reference the example in the PR description.

## Updating API Documentation

When contributing to the API, ensure that the documentation in `docs/api_reference.md` is updated to reflect your changes. Follow the structure outlined in the file to maintain consistency.

## Troubleshooting Build Errors

If you encounter build errors while contributing, refer to the [Troubleshooting Guide](docs/troubleshooting.md) for solutions to common issues.

## Scripts Cleanup

The `scripts/` directory has been cleaned up to remove unused scripts. Contributors should ensure they are using the updated list of scripts.

## Updating Dependencies

When updating dependencies, ensure the following:

1. Use the latest stable versions of all dependencies.
2. Verify that the updates do not introduce breaking changes.
3. Update any relevant documentation, including `README.md` and `docs/dependencies.md`.
4. Test the project thoroughly to ensure compatibility with the updated dependencies.

## Pre-Commit Hooks for Code Formatting

To ensure consistent code formatting, pre-commit hooks have been added. These hooks automatically format code before commits are made. Contributors should:

1. Install the pre-commit hooks by running the setup script: `scripts/setup_hooks.sh`.
2. Ensure all code adheres to the formatting rules defined in `.clang-format`.
3. Verify that the hooks are functioning correctly by attempting a commit.