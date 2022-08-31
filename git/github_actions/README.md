# Github actions

## Summary

GitHub Actions is a continuous integration and continuous delivery (CI/CD) platform that allows you to automate your build, test, and deployment pipeline. You can create workflows that build and test every pull request to your repository, or deploy merged pull requests to production.

## Technical Aspects

* Workflows are defined in the `./.github/workflows` directory.
* Each workflow is defined in a YAML file format.
* You can reuse workflows in other workflows

## Easy example

```yml
name: setup-node-and-install # the name of the github action
on: [push] # when shall the job be executed (in this case everytime something gets pushed to the repo)
jobs: # a GitHub Action has jobs which will be executed
  run-unit-tests: # each job has a name
    runs-on: ubuntu-latest # the platform on which the job shall run
    steps: # each job has steps
      - uses: actions/checkout@v3 # we use a public reusable GitHub Action which clones and checkouts our current repo
      - uses: actions/setup-node@v3 # this is another public reusable GitHub Action which setups node, so we can use node without having to install it ourselves
        with: # Reusable GH Actions can take inputs like the node-version in this case
          node-version: '14'
      - run: npm ci # install all dependencies
      - run: npm test # run all unittests, if these tests fail the pipeline will fail too

```

## Reuse GH Actions

You can reuse a workflow in other workflow if one of the following is true:

* Both workflows are in the same repository (private workflows)
* The reused (called) workflow is stored in a public repository, and your organization allows you to use public reusable workflows (public workflows)

## Public Workflows

You can use actions which were defined by some person before you by searching in the [GH Action marketplace](https://github.com/marketplace?type=). The most prominent example is the `action/checkout` action.

### actions/checkout

[This action](https://github.com/marketplace/actions/checkout) checks-out your repository under $GITHUB_WORKSPACE, so your workflow can access it. As most checks you do need the repository you will almost always use this action. The latext version is `3`.

```yml
- uses: actions/checkout@v3
```

### actions/setup-node

[This action](https://github.com/marketplace/actions/setup-node-js-environment) sets up a node environment. For more information look at the [docs](https://github.com/marketplace/actions/setup-node-js-environment).

```yml
steps:
- uses: actions/checkout@v3 # checkout your repo
- uses: actions/setup-node@v3 # setup node
  with:
    node-version: 16
- run: npm ci # install all dependencies
- run: npm test # run unittests
```


## Private Workflows

But what if you have no access to public repos or there is no action in the public space that satisfies your needs but you do not want to duplicate this action 10 times in you workflow (especially if it is a long action).

Then you can use `private workflows`.

You can define them anywhere, but it is good practice to defined them under `./.github/workflows/actions` and create a folder for every action. The folder then contains:

1. The action itself (in a yaml file of course)
2. And a README.md to document what the action does and how to use it properly.

## Custom unittest action

We want to run some unittests for a specific package in the current monorepo.

### Called workflows

```yml
name: 'Package unit test'
author: <your-name, your-org-name>
description: 'Run unit tests for the specified package in packages/'
inputs:
  package-name:
    description: 'The package name. Must be a folder name inside packages/'
    default: 'some-default'
    required: true
outputs:
  result:
    description: 'The result of the action'


runs:
  using: 'composite'
  steps:
    - name: run tests with coverage
      shell: sh
      working-directory: ./packages/${{ inputs.package-name }}
      run: |
        npm run test:ci --if-present
        echo '::set-output result=worked'
      env:
        MOCHA_FILE: junit/test-results.xml
```

This is an action which takes the package name as an input and outputs the result, which in this case is just a static string "worked".

You can include some artifact uploads and/or coverage reports into this action and then use this action as a reusable action for unittesting your packages.

### Caller workflow

Use this inside `steps`.

```yaml
- name: 'Run unit tests for <package-name>'
uses: ./.github/actions/package-unit-test
  with:
    package-name: '<package-name>'
```

## When can this be used?

We use this in our monorepo for running only against those packages which were changed on the current branch. To achieve this, we have different workflows in the `workflow` directory which run against a specific package only if there was change in the package. This is an example of the beginning of such package.


```yml
name: CI for a specific package
on:
  check_run:
    types:
      - completed
  pull_request:
    branches:
      - master # run on pull request for master branch
    paths:
      - 'packages/<package-name>/**' # run only when sth in this directory gets changed
      - '!packages/<package-name>/*.md' # dont run on only markdown files changes (because why should we?)
jobs:
  [...] # the actual jobs which will be only executed if something was changed which is included by the 'paths' option and if it's a pull request on to master
```