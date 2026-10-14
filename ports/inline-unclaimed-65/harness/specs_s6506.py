"""specs_s6506.py - unclaimed-65 batch 6 (docs/20-unclaimed-65.md, claim 6): ZInputAction::FreeActionDependencies. The list at
this+0x3e has slot +0x4c (writes 1), slot +0x64 (one argument: the out flag; returns the next node from a per-case chain) and
slot 0 (one argument, logs). Each node's first dword is an item pointer (zero in a third of cases). 0x634273 (cdecl) is a
logging stub; the translation cache is flushed after the patch."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    from serial_stubs import patch

    def delete_stub(e, r):
        e.calllog.append(('0x634273', e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)          # cdecl: the caller pops
    patch(c, 0x634273, c.emu.stub_fn('0x634273', delete_stub))
    _flush_code(c)

    # the node chain: each node's first dword is an item pointer (zero in a third of cases); the chain has 0..3 nodes
    nodes = []
    for _ in range(c.rng.randint(0, 3)):
        node = _rnd(c, 0x20)
        item = 0 if c.rng.random() < 0.33 else _rnd(c, 0x20)
        c.emu.w32(node, item)
        nodes.append(node)
    counter = {'i': 0}

    def out1(e, r):
        ptr = e.arg32(0)
        e.calllog.append(('list-4c', e.reg('ecx'), ()))
        e.w32(ptr, 1)
        e.ret(eax=0, argbytes=4)

    def next_node(e, r):
        i = counter['i']
        counter['i'] += 1
        e.calllog.append(('list-64', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=nodes[i] if i < len(nodes) else 0, argbytes=4)

    def list_dtor(e, r):
        e.calllog.append(('list-0', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    lst_vt = c.emu.fake_vtable('actiondeps-list', 0x70, {0x0: list_dtor, 0x4c: out1, 0x64: next_node})
    lst = _rnd(c, 0x40)
    c.emu.w32(lst, lst_vt)
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x3e, 0 if c.rng.random() < 0.2 else lst)
    return [self_]


S(0x4388a0, 'ZInputAction::FreeActionDependencies (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-65 batch 6 (residue 18); list at +0x3e: 4c, then 64 walk deleting nonzero items (1 byte), then slot 0 with 1')
