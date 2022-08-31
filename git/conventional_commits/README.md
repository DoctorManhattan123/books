# Conventional commits

When committing you should write messages that are precise and clear. If someone goes through your commits he should understand what you were doing there. To unite the style of writing commits there are conventional commits. Before writing a project you should establish the conventional way of writing commits.

# Very short summary

```txt
<type>[optional scope]: <description>
```

type can be `fix` (bugfix), `feat` (new feature), `<type>!` or `BREAKING CHANGE` (for a breaking change). Description should be written in imperative mood.

## Examples

```txt
feat: allow provided config object to extend other configs
```

```txt
fix: bufferoverflow when logging in user with 64 characters
```

# The most used conventional commits style

More infos [here](https://www.conventionalcommits.org/en/v1.0.0/)

```txt
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

The `type` of the commit message is often compared to the semantic versioning (semver).

* `fix` - indicates a bugfix in the code (PATCH version in semver)
* `feat` - indicates a new feature in the code (MINOR version in semver)
* `BREAKING CHANGE` or sometimes `feat!` - indicates a breaking change (MAJOR version in semver)


There can be other types like:

```js
[
  'build', // for build system
  'chore', // updating grunt tasks etc; no production code change
  'ci', // for continous integration
  'docs', // documentation was added
  'feat', // new feature
  'fix', // bugfix
  'perf', // performance improving
  'refactor', // refactor given code
  'revert', // revert a commit or some previous change
  'style', // formatting, missing semi colons, etc; no code change
  'test' // fix/add/refactor tests
]
```

The description should be written in imperative mood. Most of the time you do not need more.