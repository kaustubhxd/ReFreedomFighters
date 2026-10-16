"""specs_s1626.py - soundtimers batch 1626: CEVENTCONTROLLER AddActor / RemoveActor.
The event list object L (controller+4) is a Python model: its iterator (+0x4c reset, +0x64 next, +0x44 remove) walks a
list of prepared node records; its allocator (+4) hands out fresh 0x40-byte node records (pointer = node+4). The actor's
vtable +0x1e0 (IsKindOf) answers 0 or 1. Both the original and the port read the same model, so the comparison is of
the controller's own code. sys+0x40 is written as a random word (the same word both runs read)."""
import random as _r
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks


def _world(c, seq):
    r = c.rng
    clear_hooks(c)
    n_known = r.randint(0, 5)
    known = [rnd(c, 0x40) for _ in range(n_known)]
    # a random subset of known nodes is in the iterator list; actors are either one of the known node actors or new
    actors_of = {}
    for nd in known:
        a = obj(c, 0x40, {0x1e0: stub(c, seq, 1, ret=r.choice([0, 1]))})
        c.emu.w32(nd + 4, a)
        c.emu.w32(nd, r.choice([1, 2]))
        actors_of[nd] = a
    members = None   # set below: the iterator walks exactly the controller's chain (members outside it fault)
    st = {'i': 0, 'alloc': [], 'removed': []}
    pool = [rnd(c, 0x40) for _ in range(8)]

    def it4c(e, rr):
        st['i'] = 0
        e.ret(eax=0, argbytes=4)

    def it64(e, rr):
        out = e.r32(e.reg('esp') + 4)
        if st['i'] < len(members):
            cur = members[st['i']]
            st['i'] += 1
        else:
            cur = 0
        e.w32(out, 1 if cur else 0)
        e.ret(eax=cur, argbytes=4)

    def alloc4(e, rr):
        k = len(st['alloc'])
        nd = pool[k % len(pool)]
        st['alloc'].append(nd)
        e.ret(eax=nd + 4, argbytes=4)

    logbuf = c.emu.alloc(4 + 4 * 16, 4)

    def rem44(e, rr):
        n = e.r32(logbuf)
        e.w32(logbuf + 4 + 4 * (n % 16), e.r32(e.reg('esp') + 4) * 0 + 1)   # count only: the argument is a stack address
        e.w32(logbuf, n + 1)
        st['removed'].append(1)
        e.ret(argbytes=4)

    L = obj(c, 0x40, {0x4c: c.emu.stub_fn('it4c', it4c), 0x64: c.emu.stub_fn('it64', it64),
                      0x4: c.emu.stub_fn('alloc4', alloc4), 0x44: c.emu.stub_fn('rem44', rem44)})
    # the L vtable is stored into the controller's field as an embedded object pointer
    ctl = rnd(c, 0x40)
    c.emu.w32(ctl + 4, L)
    for off in (0xe, 0x12, 0x16):
        c.emu.w32(ctl + off, 0)
    # a random head chain of known nodes
    chain = [nd for nd in known if r.random() < 0.6]
    members = list(chain)
    prev = 0
    for nd in chain:
        c.emu.w32(nd + 0xc, 0)
        c.emu.w32(nd + 0x10, prev)
        if prev:
            c.emu.w32(prev + 0xc, nd)
        else:
            c.emu.w32(ctl + 0xe, nd)
        prev = nd
    if chain and r.random() < 0.5:
        c.emu.w32(ctl + 0x12, r.choice(chain))
    if chain and r.random() < 0.5:
        c.emu.w32(ctl + 0x16, r.choice(chain))
    sysobj(c, extra={0x40: r.getrandbits(32)})
    # actor for AddActor / RemoveActor: a known one half the time, else new; IsKindOf answers 0/1
    kindbit = r.choice([0, 1])
    act_obj = obj(c, 0x40, {0x1e0: stub(c, seq, 1, ret=kindbit)})
    if known and r.random() < 0.6:
        actor = actors_of[r.choice(known)]
    else:
        actor = act_obj
    return ctl, actor


def _add(c):
    seq = Seq(c)
    ctl, actor = _world(c, seq)
    return [ctl, actor]


S(0x53a910, 'CEVENTCONTROLLER::AddActor', 'thiscall', None, ret=None, gen=_add, note='batch1626; list append')


def _rem(c):
    seq = Seq(c)
    ctl, actor = _world(c, seq)
    return [ctl, actor]


S(0x53b1b0, 'CEVENTCONTROLLER::RemoveActor', 'thiscall', None, ret=None, gen=_rem, note='batch1626; list unlink')
